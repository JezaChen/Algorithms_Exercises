#include <iostream>
#include <cstdio>
using namespace std;

static const int  N_MAX = 100010*2; //记得把数组开大了
int N, M;
//DEFINE UNION FIND
int parent[N_MAX];
int height[N_MAX];

void init(const int& n)
{
    for(int i=1;i<=n;i++)
    {
        parent[i] = i;
        height[i] = 0;
    }
}

int find(int x)
{
    if(parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void unite(int x, int y)
{
    x = find(x); y = find(y);
    if(x == y) return;
    if(height[x] < height[y])  parent[x] = y;
    else
    {
        parent[y] = x;
        if(height[x] == height[y])
        {
            height[y]++;
        }
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}
//END

void solve()
{
    int testNums; cin>>testNums;
    for(int i=0;i<testNums;i++)
    {
        scanf("%d %d",&N,&M);
        getchar();
        init(2*N);
        char queryChar; int a,b;
        for(int j=0;j<M;j++)
        {
            scanf("%c%d%d",&queryChar,&a,&b);
            getchar();
            //cin>>queryChar>>a>>b;
            if(queryChar == 'D')
            {
                unite(a,b+N); unite(a+N,b);
            }
            else
            {
                if(same(a,b+N)||same(a+N,b))
                {
                    printf("In different gangs.\n");
                }
                else if(same(a,b)||same(a+N,b+N)||N == 2)
                {
                    printf("In the same gang.\n");
                }
                else
                {
                    printf("Not sure yet.\n");
                }
            }
        }
    }
}
int main()
{
    solve();
}
