#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static const int MAX = 99999;
static const int INF = 99999999;
typedef pair<int,int> P; //first is the shortest distance, and second is the number of the node.
struct edge
{
    int to; int cost;
};
int V;
vector< edge > G[MAX]; //邻接表
int d[MAX];

void dijkstra(int s)
{
    //init
    priority_queue<P, vector<P>, greater<P> > que;
    d[s] = 0;
    que.push(P(0,s));

    while(! que.empty())
    {
        P topElem = que.top(); que.pop();
        int v = topElem.second;
        if(d[v] < topElem.first) continue;
//        d[v] = topElem.first; //其实这个是不需要的，想一想就知道了
        //update
        for(int i=0; i<G[v].size();i++)
        {
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to],e.to)); //再加入到优先级队列中去
            }
        }
    }
}

void print()
{
    for(int i=0;i<V;i++)
    {
        cout<<i<<' '<<d[i]<<endl;
    }
}

int main()
{
    int E;
    while(cin>>V>>E)
    {
        for(int i=0; i<V; i++)
        {
            G[i].clear();
            d[i] = INF;
        }

        int from,to,cost;
        for(int i=0;i<E;i++)
        {
            cin>>from>>to>>cost;
            G[from].push_back(edge{to,cost});
            G[to].push_back(edge{from,cost});
        }
        int s; cin>>s;
        dijkstra(s);
        print();
    }
}
