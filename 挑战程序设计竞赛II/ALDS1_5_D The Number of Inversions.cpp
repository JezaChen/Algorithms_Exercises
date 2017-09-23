#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 200000
#define INF 2000000000
typedef long long llong;

int L[MAX/2+2],R[MAX/2+2];
llong merge(int A[],int lo,int hi,int mi)
{
    int n1=mi-lo;
    int n2=hi-mi;
    llong picks=0;
    for(int i=0;i<n1;i++) L[i]=A[lo+i]; //移至左集合
    for(int i=0;i<n2;i++) R[i]=A[mi+i]; //移至右集合
    L[n1]=R[n2]=INF;
    //开始比较
    int i=0,j=0;
    for(int k=lo;k<hi;k++)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i++];
        }
        else
        {
            A[k]=R[j++];
            picks+=n1-i; //注意是要增姐n1-i
        }
    }
    return picks;

}

llong mergeSort(int A[],int lo,int hi)
{
    int mi;
    llong v1,v2,v3;
    if(hi-lo>1)
    {
        mi=(hi+lo)>>1;
        v1=mergeSort(A,lo,mi);
        v2=mergeSort(A,mi,hi);
        v3=merge(A,lo,hi,mi);
        return v1+v2+v3;
    }
    return 0;
}
int main()
{
     int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++) cin>>A[i];
    cout<<mergeSort(A,0,n)<<endl;
}