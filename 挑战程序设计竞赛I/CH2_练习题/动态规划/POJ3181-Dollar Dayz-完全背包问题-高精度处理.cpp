#include <iostream>

#define LIMIT_ULL 100000000000000000
using namespace std;

static const int K_MAX = 101;
static const int N_MAX = 1001;
long long dp[N_MAX][2]; //0是高位，1是低位
int K,N;
void solve()
{
    dp[0][1]=1;
    for(int i=1;i<=K;i++)
    {
        for(int j=i;j<=N;j++)
        {
            dp[j][1] += dp[j-i][1];
            dp[j][0] += dp[j-i][0] + dp[j][1] / LIMIT_ULL;
            dp[j][1] %= LIMIT_ULL;
        }
    }
    if(dp[N][0]) cout<<dp[N][0];
    cout<<dp[N][1]<<endl;
}
int main()
{
    cin>>N>>K;
    solve();
}
