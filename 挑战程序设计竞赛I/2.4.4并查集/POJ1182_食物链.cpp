#include <iostream>

using namespace std;
static const int MAX_N = 399999;

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

int N,K;
static const int MAX_K = 1000001;

void solve()
{
    cin>>N>>K;
    //init
    init(3*N);
    int order, x, y;
    int ans=0;
    for(int i=0;i<K;i++)
    {
        cin>>order>>x>>y;
        if(x>N||y>N) //编号不满足要求
        {
            ans++;
            continue;
        }
        if(order==1) //第一种情况，x和y为同一类 same(x,y)
        {
            //首先判断对不对
            if(same(x,y+N)||same(x,y+N*2)) //x是A而y是B或者x是A而y是C
            {
                ans++;
            }
            else
            {
                unite(x,y);
                unite(x+N,y+N);
                unite(x+2*N,y+2*N);
            }
        }
        else //第二种情况，x吃y same(x,y+N)
        {
            if(same(x,y)||same(x,y+2*N))  ans++; //若x是A而y是A或者x是A而y是C
            else
            {
                unite(x,y+N);
                unite(x+N,y+N*2);
                unite(x+N*2,y);
            }
        }
    }
    cout<<ans<<endl;
}
int main()
{
    solve();
    return 0;
}