#include<cstdio>  
#include<algorithm>  
#include<cstring>  
#include<cmath>  
#include<string>  
using namespace std;  
int n,m,dp[2009][2009],in[27],de[27];  
char ch[2009];  
int main()  
{  
    scanf("%d%d",&n,&m);  
    scanf("%s",ch);  
    for (int i=1;i<=n;i++)   
    {  
        char c;  
        if (scanf("%c",&c)&&c=='\n') scanf("%c",&c);  
        int k1,k2;  
        scanf("%d%d",&k1,&k2);  
        in[c-'a']=k1;de[c-'a']=k2;  
    }  
    for (int i=m-1;i>=0;i--)  
    {  
        dp[i][i]=0;  
        for (int j=i+1;j<m;j++)  
        {  
            dp[i][j]=0x3f3f3f3f;//因为找最小的，别忘了开始时置为无穷大  
            if (ch[i]==ch[j]) dp[i][j]=dp[i+1][j-1];  
            dp[i][j]=min(dp[i][j],min(dp[i+1][j]+in[ch[i]-'a'],dp[i+1][j]+de[ch[i]-'a']));  
            dp[i][j]=min(dp[i][j],min(dp[i][j-1]+in[ch[j]-'a'],dp[i][j-1]+de[ch[j]-'a']));//三种情况  
            //printf("%d %d %d\n",i,j,dp[i][j]);  
        }  
    }  
    printf("%d",dp[0][m-1]);  
    return 0;  
}  
