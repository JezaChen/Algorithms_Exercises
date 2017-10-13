#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//并查集 ADT
static const int MAX_N = 99999;
int parent [MAX_N]; //父亲
int Rank[MAX_N]; //高度
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        Rank[i] = 0;
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
    if(Rank[x]<Rank[y]) parent[x]=y;
    else
    {
        parent[y]=x;
        if(Rank[x]==Rank[y]) Rank[x]++; //若x和y的高度相等，x的高度需要提升
    }
}

bool same(int x,int y) //判断x和y是否来自于同一个集合
{
    return find(x)==find(y);
}

static const int E_MAX = 1<<21;
struct edge
{
    int u,v,cost;
};
edge es[E_MAX];
bool comp(const edge& e1, const edge& e2)
{
    return e1.cost < e2.cost;
}
int V,E;
int kruskal()
{
    sort(es,es+E,comp); //将所有的边从小到大排序一遍
    init(V);
    int result = 0;
    for(int i=0;i<E;i++)
    {
        edge e = es[i];
        if(!same(e.u,e.v)) //不能存在环
        {
            unite(e.u,e.v);
            result += e.cost;
        }
    }
    return result;
}
int main()
{
    cin>>V>>E;
    edge e;
    for(int i=0;i<E;i++)
    {
        cin>>e.u>>e.v>>e.cost;
        es[i] = e;
    }
    cout<<kruskal()<<endl;
}
