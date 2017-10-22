    #include <iostream>
#include <algorithm>

using namespace std;
int N;
static const int N_MAX = 400;
int dp[40001];

struct block
{
    int h; //height
    int c; //quantity
    int a; //maximum altitude
};
block B[N_MAX];
bool comp(const block&a ,const block& b)
{
    return a.a<b.a;
}
void zeroOnePack(int height, int packCapacity) //0-1背包问题套路
{
    for(int i=packCapacity;i>=height;i--)
        dp[i] = max(dp[i],dp[i-height]+height);
}

void completePack(int height, int packCapacity)
{
    for(int i=height;i<=packCapacity;i++)
        dp[i] = max(dp[i],dp[i-height]+height);
}

void multiPack(int height, int amount, int packCapacity)
{
    if(height * amount >= packCapacity) //直接当做完全背包问题解决
    {
        completePack(height,packCapacity);
    }
    else  //退化成0-1背包处理
    {
        int k=1;
        while(k<amount)
        {
            zeroOnePack(height*k,packCapacity);
            amount-=k;
            k<<=1;
        }
        zeroOnePack(amount*height,packCapacity);
    }
}

int solve()
{
    sort(B,B+N,comp);
    int maxHeight = B[N-1].a;
    for(int i=0;i<N;i++)
    {
        multiPack(B[i].h,B[i].c,B[i].a);
        fill(dp+B[i].a,dp+maxHeight,dp[B[i].a]);
    }
    //return dp[B[N-1].a];
    int MAX = 0;
    for(int i=0;i<=B[N-1].a;i++) MAX = max(MAX,dp[i]);
    return MAX;
}
int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>B[i].h>>B[i].a>>B[i].c;
    cout<<solve()<<endl;
}
