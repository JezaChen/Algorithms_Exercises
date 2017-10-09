#include <iostream>

using namespace std;
static const int MAX_N = 99999;

int parent [MAX_N]; //父亲
int rank[MAX_N]; //高度
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        rank[i] = 0;
        parent[i] = i; //自身为自身的父亲
    }
}

int find(int x) //查询该点所在的树的树根
{
    if(parent[x]==x) return x;
    else return find(parent[x]); //递归寻找
}

void unite(int x, int y) //合并x和y的集合
{
    x = find(x);
    y = find(y);
    if(x==y) return; //若相同，意味着x和y来自于同一个集合
    if(rank[x]<rank[y]) parent[x]=y;
    else
    {
        parent[y]=x;
        if(rank[x]==rank[y]) rank[x]++; //若x和y的高度相等，x的高度需要提升
    }
}

bool same(int x,int y) //判断x和y是否来自于同一个集合
{
    return find(x)==find(y); 
}

int main()
{
}