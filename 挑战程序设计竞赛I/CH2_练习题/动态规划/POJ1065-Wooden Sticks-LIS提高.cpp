#include <iostream>
#include <algorithm>

using namespace std;
static const int N_MAX = 5001;
static const int INF = 1<<21;

int N;
struct stick
{
    int l,w;
};
stick S[N_MAX];
int dp[N_MAX];
bool comp(const stick& a, const stick& b)
{
    return a.l > b.l;
}
int solve()
{
    //init
    fill(dp,dp+N,INF); //降序排列

    sort(S,S+N,comp);
    for(int i=0;i<N;i++)
    {
        *lower_bound(dp,dp+N,S[i].w) = S[i].w;
    }

    return lower_bound(dp,dp+N,INF) - dp;
}
int main()
{
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>N;
        for(int j=0;j<N;j++)
            cin>>S[j].l>>S[j].w;
        cout<<solve()<<endl;
    }
}
