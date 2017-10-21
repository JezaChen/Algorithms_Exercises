#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;
static const int N_MAX = 2001;
static const int INF = 1<<21;

int dp[2][N_MAX];
int A[N_MAX];
int B[N_MAX];

int N;
int solveUp()
{
    //init
    sort(B+1,B+N+1);
    for(int j=1;j<=N;j++)
    {
        dp[1][j] = abs(A[1] - B[j]);
    }

    for(int i=2;i<=N;i++)
    {
        int preMinCost = dp[(i-1)%2][1];
        for(int j=1;j<=N;j++)
        {
            preMinCost = min(preMinCost,dp[(i-1)%2][j]);
            dp[i%2][j] = preMinCost + abs(A[i]-B[j]);
        }
    }

    return *min_element(dp[N%2]+1,dp[N%2]+N+1);
}

int solveDown()
{
    //init
    sort(B+1,B+N+1);
    for(int j=1;j<=N;j++)
    {
        dp[1][j] = abs(A[1] - B[N+1-j]);
    }

    for(int i=2;i<=N;i++)
    {
        int preMinCost = dp[(i-1)%2][1];
        for(int j=1;j<=N;j++)
        {
            preMinCost = min(preMinCost,dp[(i-1)%2][j]);
            dp[i%2][j] = preMinCost + abs(A[i]-B[N+1-j]);
        }
    }

    return *min_element(dp[N%2]+1,dp[N%2]+N+1);
}
int main()
{
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin >> A[i];
        B[i] = A[i];
    }
    cout<<min(solveDown(),solveUp())<<endl;
}
