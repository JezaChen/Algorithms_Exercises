#include <iostream>

using namespace std;

static const int V_MAX = 9999;
static const int INF = 99999999;
int V;
int d[V_MAX][V_MAX];

void warshall_floyd()
{
    for(int k=0;k<V;k++)
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}

int main()
{
    int E;
    cin>>V>>E;
    //init
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
        {
            if(i==j) d[i][j] = 0;
            else d[i][j]=INF;
        }
    //start
    int from,to,cost;
    for(int i=0;i<E;i++)
    {
        cin>>from>>to>>cost;
        d[from][to] = cost;
        d[to][from] = cost;
    }
    warshall_floyd();
    int u,v;
    while(cin>>u>>v)
    {
        cout<<d[u][v]<<endl;
    }
}
