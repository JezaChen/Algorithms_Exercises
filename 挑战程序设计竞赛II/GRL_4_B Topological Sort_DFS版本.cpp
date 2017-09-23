#include <iostream>
#include <vector>
#include <list>

static const int MAX = 100000;
using namespace std;

vector<int> G[MAX];
bool Visited[MAX];
list<int> result;
void dfs(int u)
{
    Visited[u]=true;
    for(int i=0;i<G[u].size();i++)
        if(Visited[G[u][i]]==false)  dfs(G[u][i]);

    //result.push_back(u);
    result.push_front(u);
}
int main()
{
    int n,e;
    cin>>n>>e;
    //init
    for(int i=0;i<n;i++)
       Visited[i]=false;
    int s,t;
    for(int i=0;i<e;i++)
    {
        cin>>s>>t;
        G[s].push_back(t);
    }

    //begin
    //pay attention to the forest!!
    for(int i=0;i<n;i++)
    {
        if(Visited[i]==false)
            dfs(i);
    }
    //print
    for(list<int>::iterator it=result.begin();it!=result.end();it++)
        cout<<*it<<endl;
}