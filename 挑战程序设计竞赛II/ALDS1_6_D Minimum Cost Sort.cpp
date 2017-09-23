#include <iostream>
#include <algorithm>
using namespace std;

static const int N_MAX=1000;
static const int W_MAX=10000;

int n; //数目
int A[N_MAX],B[N_MAX]; //A是乱序数组，B是已经排好序的数目
int s;//s是全体数组的最小值
int T[W_MAX+1]; //该数所对应再排好序的数组的下标值

int solve()
{
    int ans=0; //成本；
    bool V[N_MAX]; //是否被访问过
    for(int i=0;i<n;i++)
    {
        B[i]=A[i]; //把数组复制过去
        V[i]=false; //初始化
    }
    sort(B,B+n); //排序
    for(int i=0;i<n;i++) T[B[i]]=i; //初始化某个值对应排好序的数组的下标
    for(int i=0;i<n;i++)
    {
        if(V[i]) continue; //如果被访问过了，跳过
        int cur=i; //当前下标
        int S=0; //S记录某个圈的所有节点的值之和
        int m=W_MAX; //m是用于记录该圈所有节点的最小值
        int an=0; //an为圈内元素数目
        while(1) //开始遍历
        {
            V[cur]=true; //开始标记
            an++; //数目加一
            int v=A[cur]; //v为当前节点的值
            m=min(m,v); //记录圈内的最小值
            S+=v; //该圈所有节点的值总和加上当前节点的值
            cur=T[v]; //进行下一个节点的操作，找到下一个下标
            if(V[cur]) break; //如果下一个节点已经被遍历过，则该圈的所有的节点已经全部被遍历
        }
        ans+=min(S+(an-2)*m,m+S+(an+1)*s);
    }
    return ans;
}
int main()
{
    cin>>n;
    s=W_MAX;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        s=min(s,A[i]);
    }
    cout<<solve()<<endl;
}