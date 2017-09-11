#include <iostream>

using namespace std;
static const int N=100;
int main()
{
    int M[N][N];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            M[i][j]=0;
    for(int i=0;i<n;i++)
    {
        int j,num;
        cin>>j>>num;
        for(int a=0;a<num;a++)
        {
            int k;
            cin>>k;
            M[j-1][k-1]=1;
        }
    }
    //print
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<M[i][j];
            if(j==n-1) cout<<endl;
            else cout<<" ";
        }
    }

}