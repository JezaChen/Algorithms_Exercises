#include <iostream>

using namespace std;
int Fibonacci(int n)
{
    int dp[n];
    for(int i=0;i<=n;i++)
    {
        if(i==0||i==1) dp[i]=1;
        else dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main()
{
    int n;
    while(cin>>n)
        cout<<Fibonacci(n)<<endl;
}