#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
static const int N_MAX = 2010;
static const int M_MAX = 10010;
int parent[N_MAX];
int Rank[N_MAX];
int N,M;

void init()
{
    for(int i=0;i<M;i++)
    {
        parent[i] = i;
        Rank[i] = 0;
    }
}

int find(int x)
{
    if( parent[x] != x ) return find(parent[x]);
    else return x;
}

void unite(int x, int y)
{
    int x_p = find(x);
    int y_p = find(y);
    if( Rank[x_p] < Rank[y_p] )
    {
        parent[x_p] = y_p;
    }
    else
    {
        parent[y_p] = x_p;
        if( Rank[x_p] == Rank[y_p] )
        {
            Rank[x_p]++;
        }
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

struct edge
{
    int from; int to; int cost;
};

bool lessComp(const edge& a, const edge& b)
{
    return a.cost < b.cost;
}

void solve()
{
    cin>>N>>M;
    init();
    vector<edge> V;
    int ans = -1;

    int _from, _to, _cost;
    for(int i=0;i<M;i++)
    {
        cin>>_from>>_to>>_cost;
        V.push_back(edge{_from,_to,_cost});
    }

    sort(V.begin(),V.end(),lessComp);

    for(int i=0;i<V.size();i++)
    {
        int u = V[i].from; int v = V[i].to;
        if( !same(u,v) )
        {
            ans = max(ans,V[i].cost);
            unite(u,v);
        }
    }

    cout<<ans<<endl;
}

int main()
{
    solve();
    return 0;
}
