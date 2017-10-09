#include <iostream>
#include <vector>

using namespace std;

static const int MAX_E =99999;
static const int MAX_V =9999;
static const int INF=99999999;
struct edge
{
    int from; //起点
    int to; //终点
    int cost; //权重
};
vector<edge> es;
int d[MAX_V]; //最短距离
int V,E; //顶点数、边数

void Bellman_Ford(int s)
{
    //init
    for(int i=0;i<V;i++) d[i]=INF;

    d[s]=0;//起点的最短路径当然是0
    while(true)
    {
        bool is_updated = false;
        for(int i=0;i<es.size();i++) //遍历所有的边
        {
            edge e = es[i];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost)
            {
                d[e.to] = d[e.from] + e.cost;
                is_updated = true;
            }
        }
        if(!is_updated) break;
    }
}
int main()
{
    cin>>V>>E;
    int a,b,c;
    for(int i=0;i<E;i++)
    {
        cin>>a>>b>>c;
        es.push_back(edge{a,b,c});
        es.push_back(edge{b,a,c});
    }
    int s; cin>>s;
    Bellman_Ford(s);
    for(int i=0;i<V;i++)
    {
        cout<<i<<' '<<d[i]<<endl;
    }
}
