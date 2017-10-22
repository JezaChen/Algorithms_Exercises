#include <iostream>
#include <cstring>

using namespace std;
static const int N_MAX = 101;
static const int S_MAX = 1001;
int dp[200010];
static const int mid = 100005;
int range;
int S[N_MAX];
int F[N_MAX];
int N;

void zeroOnePack(int weight, int value, int packRange)
{
    if(weight>=0)
    {
        for (int i = mid + packRange; i - weight >= mid - packRange; i--)
            dp[i] = max(dp[i - weight] + value, dp[i]);
    }
    else
    {
        for(int i = mid - packRange; i - weight <= mid + packRange; i++)
            dp[i] = max(dp[i - weight] + value, dp[i]);
    }
}

int solve()
{
    memset(dp,0x80,sizeof(dp));
    dp[mid] = 0;
    //input
    cin>>N;
    int sSum = 0;
    for(int i=1;i<=N;i++)
    {
        cin>>S[i]>>F[i];
        sSum += (S[i] > 0? S[i] : 0);
    }
    //handle
    for(int i=1;i<=N;i++)
    {
        zeroOnePack(S[i],F[i],sSum);
    }
    int ans = -1;
    for(int i=mid; i<= mid + sSum; i++)
    {
        if(dp[i] > 0)  ans = max(ans, dp[i] + i - mid);
    }
    return ans;
}
int main()
{
    cout<<solve()<<endl;
    return 0;
}
