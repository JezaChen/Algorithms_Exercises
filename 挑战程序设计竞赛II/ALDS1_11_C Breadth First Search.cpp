#include <iostream>
#include <vector>
#include <queue>
using namespace std;
static const int MAX=101;

vector<int> Adjacency[MAX];
int dt[MAX];
bool Visited[MAX];

void bfs(int i)
{
    queue<int> Q;
    dt[i]=0;Q.push(i);
    Visited[i]=true;
    int d=0;
    while(!Q.empty())
    {
        int p=Q.front();Q.pop();d=dt[p]+1; //important
        for(int j=0;j<Adjacency[p].size();j++)
        {
            if(Visited[Adjacency[p][j]]==true) continue;
            //else
            Q.push(Adjacency[p][j]); Visited[Adjacency[p][j]]=true;
            dt[Adjacency[p][j]]=d;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) dt[i]=-1;
    for(int i=1;i<=n;i++)
    {
        int j,num;
        cin>>j>>num;
        for(int k=0;k<num;k++)
        {
            int t;cin>>t;
            Adjacency[j].push_back(t);
        }
    }
    bfs(1);
    for(int i=1;i<=n;i++)
    {
        cout<<i<<' '<<dt[i]<<endl;
    }
}