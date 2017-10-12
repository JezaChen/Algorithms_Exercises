#include <iostream>
#include <stack>
#include <vector>

using namespace std;
typedef pair<int,int> P;
static const int V_MAX = 99999;
static const int INF = 99999999;
int V;
int d[V_MAX];
bool used[V_MAX];
int par[V_MAX];
vector<P> G[V_MAX];

void dijkstra(int s)
{
    //init
    for(int i=0;i<V;i++)
    {
        used[i]=false;
        d[i] = INF;
    }
    d[s]=0;
    while(true)
    {
        //select
        int v = -1;
        for(int u=0;u<V;u++)
        {
            if(!used[u] && (v == -1 || d[v] > d[u]))
            {
                v=u;
            }
        }
        if(v==-1) break;
        used[v]=true;
        //update
        for(int i=0;i<G[v].size();i++)
        {
            int u=G[v][i].first;
            int cost=G[v][i].second;
            if(d[u] > d[v] + cost)
            {
                d[u] = d[v] + cost;
                par[u] = v;
            }
        }
    }
}
void print_par(int u, int v)
{
    stack<int> S;
    S.push(v);
    while(par[v]!=u)
    {
        S.push(par[v]);
        v = par[v];
    }
    S.push(u);
    while(!S.empty())
    {
        cout<<S.top()<<' ';
        S.pop();
    }
    cout<<'\b'<<endl;
}

int main()
{
    int E;
    cin>>V>>E;
    //init
    for(int i=0;i<V;i++)
    {
        G[i].clear();
    }
    //start
    int from,to,cost;
    for(int i=0;i<E;i++)
    {
        cin>>from>>to>>cost;
        G[from].push_back(make_pair(to,cost));
        G[to].push_back(make_pair(from,cost));
    }
    int u,v;
    while(cin>>u>>v)
    {
        dijkstra(u);
        cout<<d[v]<<endl;
        cout<<"Route: ";
        print_par(u,v);
    }
}
