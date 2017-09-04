#include <iostream>
using namespace std;

int NUM[1000001];
int n;
bool BinSearch(int target)
{
    int hi=0;int lo=n;
    while(hi<lo)
    {
        int mi=(hi+lo)/2;
        if(target<NUM[mi])
        {
            lo=mi;
            continue;
        }
        else if(target>NUM[mi])
        {
            hi=mi+1;
            continue;
        }
        else
        {
            return true;
        }
    }
    return false;
}
int main() {
   cin>>n;
    int p=0;
    for(int i=0;i<n;i++)
        cin>>NUM[i];
    int q;
    cin>>q;
    for(int j=0;j<q;j++)
    {
        int t;
        cin>>t;
        if(BinSearch(t)) p++;
    }
    cout<<p<<endl;
}