#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
static const int MAX=10000;
static const int INFTY = (1<<21);

vector< pair<int,int> >M[MAX]; //邻接表
priority_queue< pair<int,int> > PQ; //优先级队列, first是d[i], second是i， 使用时需要把first取相反数
bool visited[MAX]; //是否被访问过
int d[MAX]; //最短路径成本

void dijkstra_implementsPQ(int n)
{
    //init
    for(int i=0;i<n;i++)
    {
        d[i]=INFTY;
        visited[i]=false;
    }
    //select node 0
    d[0]=0;
    PQ.push(make_pair(0,0));

    while(!PQ.empty())
    {
        //currently the top of PQ is the shortest one
        pair<int,int> temp=PQ.top();PQ.pop();
        int u=temp.second;

        visited[u]=true;
        if(d[u]<temp.first*(-1)) continue;

        //update
        for(int j=0;j<M[u].size();j++)
        {
            int v=M[u][j].first;
            if(visited[v]==true) continue;
            //else try updating
            if(d[v]>d[u]+M[u][j].second)
            {
                d[v]=d[u]+M[u][j].second;
                PQ.push(make_pair(d[v]*(-1),v));
            }
        }
    }
    //print
    for(int i=0;i<n;i++)  cout<<i<<' '<<(d[i]==INFTY?-1:d[i])<<endl;

}
int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int u,k;
        cin>>u>>k;
        for(int j=0;j<k;j++)
        {
            int v,d;
            cin>>v>>d;
            M[u].push_back(make_pair(v,d));
        }
    }

    dijkstra_implementsPQ(n);
}