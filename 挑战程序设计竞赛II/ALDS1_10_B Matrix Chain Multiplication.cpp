#include <iostream>
#include <algorithm>
using namespace std;
static const int N=100;

int main()
{
   int n,p[N+1],m[N+1][N+1];  //说明：对于第i个矩阵，它是p[i-1]*p[i]的；m[i][j]指的是矩阵i到j中的链中的最优解
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>p[i]>>p[i+1];

    //init
    for(int i=1;i<=n;i++) m[i][i]=0;
    for(int l=2;l<=n;l++) //从长度2的矩阵链开始处理，一直处理到长度为n
    {
        for(int i=1;i<=n-l+1;i++) //从该长度的矩阵链的第一个对象开始处理
        {
            int j=i+l-1; //末端
            m[i][j]=1<<21; //先取一个极大值
            for(int k=i;k<j;k++)
            {
                m[i][j]=min(m[i][j],m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]);  //依次取最小值
            }
        }
    }
    cout<<m[1][n]<<endl;
}