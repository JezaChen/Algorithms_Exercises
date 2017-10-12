#include <iostream>
#include <vector>

using namespace std;
static const int N_MAX = 999999;
static const int INF = 99999999;

int N;
vector< pair<int,int> > Edge[N_MAX]; //邻接表
bool used[N_MAX]; //是否已经加入了集合
int d[N_MAX]; //与集合中某一点的最短距离

void dijkstra(int s)
{
    d[s] = 0;
    while(true)
    {
        int v = -1;
        //选择d最小的点
        for(int u = 0; u<N; u++)
        {
            if(!used[u] && (v == -1 || d[u] < d[v]))
                v = u;
        }
        if(v == -1) break;

        used[v] = true; //加入集合

        //更新d值
        for(int i=0; i<Edge[v].size(); i++)
        {
            int u=Edge[v][i].first;
            int cost = Edge[v][i].second;
            d[u] = min(d[u], d[v] + cost);
        }
    }
}

void print()
{
    for(int i=0;i<N;i++)
    {
        cout<<i<<' '<<d[i]<<endl;
    }
}

int main()
{
    int E;
    while(cin>>N>>E)
    {
        for(int i=0; i<N; i++)
        {
            used[i] = false;
            Edge[i].clear();
            d[i] = INF;
        }

        int from,to,cost;
        for(int i=0;i<E;i++)
        {
            cin>>from>>to>>cost;
            Edge[from].push_back(make_pair(to,cost));
            Edge[to].push_back(make_pair(from,cost));
        }
        int s; cin>>s;
        dijkstra(s);
        print();
    }
}
