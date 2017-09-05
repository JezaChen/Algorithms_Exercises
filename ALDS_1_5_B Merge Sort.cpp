#include <iostream>
using namespace std;

#define MAX 500000
#define INF 2000000000

int L[MAX/2+2];
int R[MAX/2+2];
int picks=0;

void merge(int A[],int lo,int hi,int mid)
{
    int n1=mid-lo; //用于左边计数
    int n2=hi-mid; //用于右边计数
    for(int i=0;i<n1;i++) L[i]=A[lo+i];
    for(int i=0;i<n2;i++) R[i]=A[mid+i];
    L[n1]=R[n2]=INF;
    int i=0,j=0;

    //开始比较
    for(int k=lo;k<hi;k++)
    {
        if(L[i]<=R[j]) A[k]=L[i++];
        else A[k]=R[j++];
        picks++;
    }
    return;
}

void mergeSort(int A[],int lo,int hi)
{
    if(hi-lo>1) //当有不少于两个的元素的时候
    {
       //int mid=(hi-lo)/2;
        int mid=(hi+lo)/2;
        mergeSort(A,lo,mid);
        mergeSort(A,mid,hi);
        merge(A,lo,hi,mid);
    }
    return ;
}
int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    mergeSort(A,0,n);
    for(int i=0;i<n;i++)
    {
        cout<<A[i];
        if(i==n-1) cout<<endl;
        else cout<<' ';
    }
    cout<<picks<<endl;
}