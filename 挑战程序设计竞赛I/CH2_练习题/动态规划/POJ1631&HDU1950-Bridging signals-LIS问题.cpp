#include <iostream>

using namespace std;
static const int N_MAX = 40001;
static const int INF = 1<<21;
int N;
int dp[N_MAX];
int edge[N_MAX];

long solve()
{
    fill(dp,dp+N,INF);

    for(int i=0;i<N;i++)
        *lower_bound(dp,dp+N,edge[i]) = edge[i];

    return lower_bound(dp,dp+N,INF) - dp;
}
int main()
{
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        cin>>N;
        for(int j=0;j<N;j++)
            cin>>edge[j];
        cout<<solve()<<endl;
    }
}
