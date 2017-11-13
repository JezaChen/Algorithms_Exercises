#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

static const int MAX_V = 10000;
static const int INF = 1<<21;

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
    while(true)
    {
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if(f == 0) return flow;
        flow += f;
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
        add_edge(from, to ,cap);
    }
    cout<<maxFlow(0,V-1)<<endl;
}
