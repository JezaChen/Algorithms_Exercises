#include <iostream>
#include <cstring>

using namespace std;
static const int N_MAX = 101;
static const int M_MAX = 100001;
int N,M;
bool dp [100001];

void completePack(int value, int packCapacity)//完全背包问题的处理套路
{
    for(int i=value;i<=packCapacity;i++)
    {
        //if(i<value) dp[i] = dp[i];
        dp[i] = dp[i-value]|dp[i];
    }
}

void oneZeroPack(int value, int packCapacity) //0-1背包问题处理套路
{
    for(int i=packCapacity;i>=value;i--)
    {
        dp[i] = dp[i-value]|dp[i];
    }
}

void multiPack(int value, int amount, int packCapacity) //多重背包问题的套路代码
{
    if (value * amount >= packCapacity)
    {
        completePack(value, packCapacity);
        return;
    }
    else
    {
        int k = 1;
        while (k < amount) {
            oneZeroPack(value * k, packCapacity);
            amount -= k;
            k <<= 1;
        }
        oneZeroPack(value * amount, packCapacity);
    }
}

int solve()

{
    while(cin>>N>>M)
    {
        if(!N && !M) break;
        int value[N],amount[N];
        for(int i=0;i<N;i++)
            cin>>value[i];
        for(int i=0;i<N;i++)
            cin>>amount[i];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for(int i=0;i<N;i++)
        {
            multiPack(value[i],amount[i],M);
        }
        int result = 0;
        for(int i=1;i<=M;i++) result += dp[i];
        cout<<result<<endl;
    }
}
int main()
{
    solve();
    return 0;
}
