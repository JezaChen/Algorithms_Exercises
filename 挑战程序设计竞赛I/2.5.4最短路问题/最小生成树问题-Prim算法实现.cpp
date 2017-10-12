#include <iostream>
#include <vector>

using namespace std;
static const int MAX_V = 99999;
static const int INF = 9999999;
typedef pair<int,int> P;

vector<P> G[MAX_V];
bool used[MAX_V];
int minCost[MAX_V];
int V;

int prim()
{
    int result=0;
    //init
    for(int i=0;i<V;i++)
    {
        minCost[i] = INF;
        used[i]= false;
    }
    minCost[0]=0;
    while(true)
    {
        int v = -1;
        //select
        for(int u=0;u<V;u++)
        {
            if(!used[u] && (v==-1 || minCost[v] > minCost[u]))
            {
                v = u;
            }
        }
        if(v==-1) break;
        used[v] = true;
        result += minCost[v];
        //update
        for(int i=0;i<G[v].size();i++)
        {
            int u=G[v][i].first;
            int cost=G[v][i].second;
            minCost[u] = min(minCost[u], cost);
        }
    }
    return result;
}
int main()
{
    int E;
    cin>>V>>E;
    int a,b,cost;
    for(int i=0;i<E;i++)
    {
        cin>>a>>b>>cost;
        G[a].push_back(make_pair(b,cost));
        G[b].push_back(make_pair(a,cost));
    }
    cout<<prim()<<endl;
}
