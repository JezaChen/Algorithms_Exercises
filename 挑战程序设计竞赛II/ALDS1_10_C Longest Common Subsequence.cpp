#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int LCS(const char* a,const char* b)
{
    int m=strlen(a); int n=strlen(b); //i为字符串a的长度，j为字符串b的长度
    int c[m+1][n+1]; //c数组的作用是记录字符串a的前i位和字符串b的前j位之间的LCS
    for(int i=0;i<=m;i++) c[i][0]=0;
    for(int i=0;i<=n;i++) c[0][i]=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            if(a[i]==b[j]) c[i+1][j+1]=c[i][j]+1;
            else
            {
                c[i+1][j+1]=max(c[i][j+1],c[i+1][j]);
            }
        }
    return c[m][n];

}
int main()
{
    char *a=new char[1001];
    char *b=new char[1001];
    int q;
    while(cin>>q)
    {
        for(int i=0;i<q;i++)
        {
            cin>>a>>b;
            cout<<LCS(a,b)<<endl;
        }
    }
}