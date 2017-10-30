#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>

using namespace std;

static const int K_MAX = 10010;
static const int N_MAX = 10010;
static const int L_MAX = 100010;
static const int INF = 1<<21;
int N;
double ropes [N_MAX];

int C(double length)
{
    int ans = 0.;
    for(int i=0;i<N;i++)
    {
        ans += int( ropes[i] / length );
    }
    return ans;
}

void solve()
{
    int K;
    cin>>N>>K;
    for(int i=0;i<N;i++)
        cin>>ropes[i];
    double lo = 0, hi = INF, mid;
    for(int i=0;i<100;i++) //为了逼近答案
    {
        mid = ( lo + hi )/2;
        if( C(mid) >= K ) lo = mid;
        else hi = mid;
    }
    printf("%.2f\n",floor(mid*100)/100);
}
int main()
{
    solve();
    return 0;
}
