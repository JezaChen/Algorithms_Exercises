#include <iostream>
#include <string>
#include <cstring>

using namespace std;
static const int M_MAX = 2001;
static const int N_MAX = 27;
static const int INF = 1<<21;
int cost[N_MAX];
int dp[M_MAX][M_MAX];
char letter[M_MAX];
int N,M;
int solve()
{
    int n = M;
    //init
    for(int i=0;i<n;i++)  dp[i][i] = 0;
    for(int length=2;length<=n;length++)
    {
        for(int i=0,j=i+length-1;j<n;i++,j++)
        {
            dp[i][j] = INF;
            if(letter[i] == letter[j])
            {
                dp[i][j] = dp[i+1][j-1];
            }
            else
            {
                dp[i][j] = min(dp[i+1][j]+cost[letter[i]-'a'],dp[i][j-1]+cost[letter[j]-'a']);
            }
        }
    }
    return dp[0][n-1];
}

int main()
{
    cin>>N>>M;
    //memset(dp,M_MAX*M_MAX,0);
    cin>>letter;
    char c; int a,b;
    for(int i=0;i<N;i++)
    {
        cin>>c;
        cin>>a>>b;
        cost[c-'a'] = min(a,b);
    }
    cout<<solve()<<endl;
}
