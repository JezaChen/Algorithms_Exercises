#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int pos,n;
vector<int> pre,in,post;

void rec(int lo,int hi) //递归重建算法
{
    if(lo>=hi)  //递归基
    return;
    int root=pre[pos++];
    int m=distance(in.begin(),find(in.begin(),in.end(),root));

    rec(lo,m);
    rec(m+1,hi);

    post.push_back(root);
}

void solve()
{
    pos=0;
    rec(0,pre.size());
    for(int i=0;i<n;i++)
    {
        if(i) cout<<" ";
        cout<<post[i];
    }
    cout<<endl;
}
int main()
{
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            int j;cin>>j;
            pre.push_back(j);
        }
        for(int i=0;i<n;i++)
        {
            int j;cin>>j;
            in.push_back(j);
        }
        solve();
    }
}