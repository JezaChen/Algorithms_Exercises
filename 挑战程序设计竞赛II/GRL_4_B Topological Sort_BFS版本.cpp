#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>

using namespace std;
static const int MAX=100000;

vector<int> G[MAX];
list<int> result;
int n;
int indeg[MAX]; //各节点的入度
bool Visited[MAX];

void bfs(int s)
{
    queue<int> Q;
    Q.push(s); //根节点入队
    Visited[s]=true;
    while(!Q.empty())
    {
        int u=Q.front(); Q.pop();
        //enqueue
        result.push_back(u); //注意bfs遍历的顺序就是结果的顺序
        //trav
        for(int i=0;i<G[u].size();i++)
        {
            int v=G[u][i];
            indeg[v]--; //入度减一
            if(indeg[v]==0&&!Visited[v])  //依次将入度为0的节点加入队列中去
            {
                Visited[v]=true;
                Q.push(v);
            }
        }
    }
}

void tsort()
{
    //init
    for(int i=0;i<n;i++)
        indeg[i]=0;
    //count the indeg of every node
    for(int i=0;i<n;i++)
        for(int j=0;j<G[i].size();j++)
            indeg[G[i][j]]++;
    //begin bfs
    for(int i=0;i<n;i++)
        if(indeg[i]==0&&!Visited[i]) bfs(i); //入度为0的节点作为根节点进行bfs遍历
    //print
    for(list<int>::iterator it=result.begin();it!=result.end();it++)
        cout<<*it<<endl;
}
int main()
{
    int e;
    cin>>n>>e;
    //init
    for(int i=0;i<n;i++) Visited[i]=false;

    int s,t;
    for(int i=0;i<e;i++)
    {
        cin>>s>>t;
        G[s].push_back(t);
    }

    //begin tsort
    tsort();
}