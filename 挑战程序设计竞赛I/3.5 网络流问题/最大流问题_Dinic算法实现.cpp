#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

static const int MAX_V = 10000;
static const int INF = 1 << 21;

struct edge
{
    int to, cap, rev; //终点、容量、反向边在指向点中对应的编号
};

vector<edge> G[MAX_V]; //图的邻接表表示
int level[MAX_V];
int iter[MAX_V];

void addEdge(int from, int to, int cap)
{
    G[from].push_back((edge) {to, cap, (int) G[to].size()});
    G[to].push_back((edge) {from, 0, (int) G[from].size() - 1});
}

void bfs(int s) //通过BFS计算从源点出发的距离标号
{
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        for (int i = 0; i < G[v].size(); i++)
        {
            edge &e = G[v][i];
            if (e.cap > 0 && level[e.to] < 0)
            {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f) //通过DFS寻找增广路
{
    if (v == t) return f;
    for (int &i = iter[v]; i < G[v].size(); i++)
    {
        edge &e = G[v][i];
        if (e.cap > 0 && level[v] < level[e.to])
        {
            int d = dfs(e.to, t, min(e.cap, f));
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
    while(true)
    {
        bfs(s);
        if(level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while((f = dfs(s, t, INF)) > 0) flow +=f;
    }
}

int main()
{
    //test
    int V,E;
    cin>>V>>E;
    for(int i=0;i<E;i++)
    {
        int from, to, cap;
        cin>>from>>to>>cap;
        addEdge(from, to ,cap);
    }
    cout<<maxFlow(0,V-1)<<endl;

}
