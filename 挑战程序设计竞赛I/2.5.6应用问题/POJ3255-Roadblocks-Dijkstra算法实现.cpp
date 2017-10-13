#include <iostream>
//#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> P;
struct edge
{
    int to;
    int cost;
};

static const int MAX_E = 100000;
static const int MAX_V = 5000;
static const int INF = (1<<21);

int V,E;
vector<edge> G[MAX_V]; //邻接表

int dist[MAX_V]; //最短距离
int dist2[MAX_V]; //次短距离

void solve()
{
    priority_queue<P, vector<P>,greater<P> > que;
    //init
    fill(dist,dist+V,INF);
    fill(dist2,dist2+V,INF);
    dist[0]=0;
    que.push(P(0,0));

    while(!que.empty())
    {
        P p = que.top(); que.pop();
        int u=p.second;
        int d=p.first;
        if(dist2[u] < d) continue;
        for(int i=0;i<G[u].size();i++)
        {
            edge& e = G[u][i];
            int v = e.to;
            int cost = e.cost;
            int d2 = d+ e.cost;
            if(dist[v] > d2)
            {
                swap(dist[v],d2);
                que.push(P(dist[v],v));
            }
            if(dist[v] < d2 && dist2[v] > d2)
            {
                dist2[v] = d2;
                que.push(P(dist2[v],v));
            }
        }
    }
    cout<<dist2[V-1]<<endl;
}

int main()
{
    cin>>V>>E;
    int a,b,cost;
    for(int i=0;i<E;i++)
    {
        cin>>a>>b>>cost;
        G[a-1].push_back(edge{b-1,cost});
        G[b-1].push_back(edge{a-1,cost});
    }
    solve();
    return 0;
}
