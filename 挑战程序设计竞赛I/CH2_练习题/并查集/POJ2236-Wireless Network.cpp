#include <iostream>
#include <cmath>

using namespace std;
static const int N_MAX = 1010;
int N;
//Define Union Find
int parent[N_MAX];
int height[N_MAX];
void init()
{
    for(int i=0; i<N_MAX; i++)
    {
        parent[i] = i;
        height[i] = 0;
    }
}

int find(int x)
{
    if(x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

void unite(int x, int y)
{
    x = find(x); y = find(y);
    if(x == y) return;
    if(height[x] < height[y])
    {
        parent[x] = y;
    }
    else
    {
        parent[y] = x;
        if(height[x] == height[y])
            height[x]++;
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

//END
int square(int x) { return x*x; }

void solve()
{
    int maxDistance;
    cin>>N>>maxDistance;
    init();
    int x[N+1], y[N+1];
    for(int i=1; i<=N; i++)
    {
        cin>>x[i]>>y[i];
    }
    //calculate the distance
    //提前计算两点间的距离，可以减少至少一半的运算量，避免超时
    bool assessed[N+1][N+1];
    for(int i=1;i<=N;i++)
    {
        for(int j=i;j<=N;j++)
        {
            assessed[j][i] = false;
            assessed[i][j] = false; //initialize the data here
            if(square(x[i]-x[j]) + square(y[i]-y[j]) <= square(maxDistance))
            {
                assessed[i][j] = true;
                assessed[j][i] = true;
            }
        }
    }
    //handle
    char queryChar; int targetComputer; bool isRepaired[N+1];
    fill(isRepaired,isRepaired+N+1,false);

    while(cin>>queryChar>>targetComputer)
    {
        if(queryChar == 'O')
        {
            isRepaired[targetComputer] = true;
            for(int i=1;i<=N;i++)
            {
                if(assessed[i][targetComputer] && isRepaired[i])
                {
                    unite(i,targetComputer);
                }
            }
        }
        else
        {
            int otherComputer; cin>>otherComputer;
            if(same(targetComputer,otherComputer))  cout<<"SUCCESS"<<endl;
            else cout<<"FAIL"<<endl;
        }
    }
}
int main()
{
    solve();
}
