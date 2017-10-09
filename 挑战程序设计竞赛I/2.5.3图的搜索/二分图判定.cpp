#include <iostream>
#include <vector>

using namespace std;
static const int MAX_N = 201;

vector<int> G[MAX_N]; //邻接矩阵
int color[MAX_N]; //节点颜色

bool dfs(int u, int c)
{
    color[u]=c; //染成颜色c
    //遍历邻接点
    for(int i=0;i<G[u].size();i++)
    {
        if(color[G[u][i]]==c) return false; //如果邻接点同色，返回true，意味着不是二分图
        if(color[G[u][i]]==0 && !dfs(G[u][i],-c)) return false; //若没有进行染色，染成相反数，就是另外一个颜色，进行递归
    }
    return true;
}

void solve(int n)
{
    for(int i=0;i<n;i++)
    {
        if (color[i] == 0)
        {
            if (!dfs(i, 1))
            {
                cout << "NOT BICOLORABLE." << endl;
                return; //记得要及时返回
            }
        }
    }
    cout<<"BICOLORABLE."<<endl;
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        //init
        for(int i=0;i<n;i++)
        {
            G[i].clear();
            color[i]=0;
        }

        int st, ed;
        for (int i = 0; i < m; i++)
        {
            cin >> st >> ed;
            G[st].push_back(ed);
            G[ed].push_back(st);
        }
        solve(n);
    }
}