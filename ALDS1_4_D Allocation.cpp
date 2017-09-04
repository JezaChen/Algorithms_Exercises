#include <iostream>
using namespace std;
#define MAX 100000
typedef long long llong;

int n,k; //n表示有n个货物，k表示有k俩货车
llong T[MAX];

int check(llong P) //运载量为P的货车能装多少个货物
{
    int i=0;
    for(int j=0;j<k;j++)
    {
        llong s=0;
        while(s+T[i]<=P)
        {
            s+=T[i];
            i++;
            if(i==n) return n;
        }
    }
    return i;
}

int solve()
{
    llong left=0;
    llong right=100000*100000;
    llong mid;
    while(right-left>1)
    {
        mid=(left+right)>>1;
        int v=check(mid);
        if(v>=n) right=mid;
        else left=mid;
    }
    return right;
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>T[i];
    cout<<solve()<<endl;
}