#include <iostream>
#include <vector>

using namespace std;
static const int MAX=101;
bool Visited[MAX]; //该节点是否被访问过
vector<int> Adjacency[MAX];
int dTime[MAX]; int fTime[MAX]; //被发现时间，被访问时间
void dfs(int i,int& clock) //时钟参数应该需要引用
{
    clock++;
    Visited[i]=true;
    dTime[i]=clock; //确定发现时间
    for(int j=0;j<Adjacency[i].size();j++)
    {
        if(Visited[Adjacency[i][j]]==true) continue;
        dfs(Adjacency[i][j],clock);
    }
    clock++; //这个还需要自增吗
    fTime[i]=clock;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) Visited[i]=false;

    for(int i=1;i<=n;i++)
    {
        int p;cin>>p;
        int num;
        cin>>num;

        for(int j=0;j<num;j++)
        {
            int t;
            cin>>t;
            Adjacency[p].push_back(t);
        }
    }
    int clock=0;
    for(int i=1;i<=n;i++)  //这是为了应对出现DFS森林的情况
    {
        if(Visited[i]==false) dfs(i,clock);
    }
    for(int i=1;i<=n;i++)
        cout<<i<<' '<<dTime[i]<<' '<<fTime[i]<<endl;
}