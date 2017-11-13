#include <iostream>
#include <vector>]

using namespace std;

static const int MAX_V = 10001;
static const int INF = 1 << 21;
struct edge
{
    int to, cap, cost, rev; //终点、容量、费用、反向边
};
int V;
vector<edge> G[MAX_V];
int shortestDist[MAX_V]; //最短路径
int prevV[MAX_V], prevE[MAX_V]; //最短路径中的前驱节点和所对应的边
void addEdge(int from, int to, int cap, int cost)
{
    G[from].push_back((edge) {to, cap, cost, (int) G[to].size()});
    G[to].push_back((edge) {from, 0, -cost, (int) G[from].size()});
}

int minCostFlow(int s, int t, int f)
{
    int res = 0;
    while (f > 0)
    {
        fill(shortestDist, shortestDist + V, INF);
        shortestDist[s] = 0;
        bool update = true;
        while (update)
        {
            update = false;
            for (int v = 0; v < V; v++)
            {
                if (shortestDist[v] == INF) continue;
                for (int i = 0; i < G[v].size(); i++)
                {
                    edge &e = G[v][i];
                    if (e.cap > 0 && shortestDist[e.to] > shortestDist[v] + e.cost)
                    {
                        shortestDist[e.to] = shortestDist[v] + e.cost;
                        prevV[e.to] = v;
                        prevE[e.to] = i;
                        update = true;
                    }
                }
            }
        }

        if (shortestDist[t] == INF) return -1;
        int d = f;
        for (int v = t; v != s; v = prevV[v])
        {
            d = min(d, G[prevV[v]][prevE[v]].cap);
        }

        f -= d;
        res += d * shortestDist[t];
        for (int v = t; v != s; v = prevV[v])
        {
            edge& e = G[prevV[v]][prevE[v]];
            e.cap -= d;
            G[v][e.rev].cap +=d;
        }
    }
    return res;
}

int main()
{
    //test
    int E;
    cin>>V>>E;
    for(int i=0;i<E;i++)
    {
        int from, to, cap, cost;
        cin>>from>>to>>cap>>cost;
        addEdge(from,to,cap,cost);
    }
    cout<<minCostFlow(0,V-1,9)<<endl;
}
