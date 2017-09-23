#include <iostream>
using namespace std;

static const int MAX=100;
static const long long INFTY=(1LL<<32);

int n;
long long d[MAX][MAX];

void floyd()
{
    //ÈýÖØÑ­»·
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            if(d[i][k]==INFTY) continue;
            for(int j=0;j<n;j++)
            {
                if(d[k][j]==INFTY) continue;
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

int main()
{
    int e;
    cin>>n>>e;
    //init
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            d[i][j]=((i==j)?0:INFTY);
    }
    int s,t,dt;
    for(int i=0;i<e;i++)
    {
        cin>>s>>t>>dt;
        d[s][t]=dt;
    }
    //begin
    floyd();
    //print
    //check the negative cycle
    bool negative=false;
    for(int i=0;i<n;i++) if(d[i][i]<0) {negative=true;break;}
    if(negative) cout<<"NEGATIVE CYCLE"<<endl;
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j) cout<<' ';
                if(d[i][j]==INFTY) cout<<"INF";
                else cout<<d[i][j];
            }
            cout<<endl;
        }
    }
    return 0;

}