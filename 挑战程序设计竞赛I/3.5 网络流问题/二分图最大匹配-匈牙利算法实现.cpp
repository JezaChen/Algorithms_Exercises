#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
static const int MAX_V = 1001;
int V;
vector<int> G[MAX_V]; //图的邻接表表示形式
int match[MAX_V]; //与之匹配的顶点
bool used[MAX_V]; //dfs所要用到的访问标记

void add_edge(int u, int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}

//匈牙利算法的核心代码
bool dfs(int v)
{
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++)
    {
        int u = G[v][i], w = match[u];
        if (w < 0 || !used[w] && dfs(w))
        {
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    return false;
}

int bipartiteMatching()
{
    int res = 0;
    memset(match, -1, sizeof(match));
    for (int v = 0; v < V; v++)
    {
        if(match[v] < 0)
        {
            memset(used, 0, sizeof(used));
            if(dfs(v)
                res++;
        }
    }
    return res;
}

int main()
{
}
