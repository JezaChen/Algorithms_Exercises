#include <iostream>
#include <cstring>

using namespace std;
static const int T_MAX = 1001;
static const int N_MAX = 100001;
int dp[2][N_MAX];
int T,M,S,B;
int a[T_MAX];

int solve()
{
    memset(dp,2*N_MAX,0);
    for(int i=0;i<2;i++) dp[i][0] = 1;
    for(int i=1;i<=T;i++)
    {
        for(int j=1;j<=B;j++)
        {
            if(j>a[i])
                dp[i%2][j] = (dp[i%2][j-1] + dp[(i-1)%2][j] - dp[(i-1)%2][j-1-a[i]] + 1000000 ) % 1000000;
            else
                dp[i%2][j] = (dp[i%2][j-1] + dp[(i-1)%2][j]) % 1000000;
        }
    }
    int ans = 0;
    for(int i=S;i<=B;i++)
        ans+=dp[T%2][i];
    return ans%1000000;
}

int main()
{
    int A;
    cin>>T>>A>>S>>B;
    memset(a,T+1,0);
    int tag;
    for(int i=1;i<=A;i++)
    {
        cin>>tag;
        a[tag]++;
    }
    cout<<solve()<<endl;
}
