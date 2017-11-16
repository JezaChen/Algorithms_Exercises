#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

static const int MAX_V = 10000;
static const int INF = 1 << 21;

//////////////二分图求解用///////////////////
int N, K;
static const int MAX_N = 1001;
static const int MAX_K = 1001;
bool can[MAX_N][MAX_K]; //can[i][j]可理解为i和j连边
//////////END

struct edge
{
    int to, cap, rev; //终点、容量、反向边在指向点中对应的编号
};

vector<edge> G[MAX_V]; //图的邻接表表示
bool used[MAX_V];

void add_edge(int from, int to, int cap)
{
    G[from].push_back(edge{to, cap, (int) G[to].size()});
    G[to].push_back(edge{from, 0, (int) G[from].size() - 1});
}

int dfs(int v, int t, int f) //f为当前可用流
{
    if (v == t) return f; //递归基
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++)
    {
        edge &e = G[v][i];
        if (!used[e.to] && e.cap > 0)
        {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0)
            {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int maxFlow(int s, int t)
{
    int flow = 0;
    while (true)
    {
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if (f == 0) return flow;
        flow += f;
    }
}

//////////////////////////////二分图求解最大匹配问题////////////////////////
int bipartiteMatching()
{
    int s = N + K;
    int t = s + 1;

    //源点和左边连边
    for (int i = 0; i < N; i++)
        add_edge(s, i, 1);

    //右边和汇点连边
    for (int i = 0; i < K; i++)
        add_edge(N+i, t, 1);
    
    //左右连边开始连边
    for(int i=0;i<N;i++)
        for(int j=0;j<K;j++)
            if(can[i][j])
                add_edge(i,N+j,1);
    
    return maxFlow(s, t);
}
////////////////////////END

int main()
{
    //test
    int V, E;
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int from, to, cap;
        cin >> from >> to >> cap;
        add_edge(from, to, cap);
    }
    cout << maxFlow(0, V - 1) << endl;
}
