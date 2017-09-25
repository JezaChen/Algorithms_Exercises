#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
int m,n; //行、列
static const int MAX=9999;

static const int INF_LO = -9999999;
static const int INF_HI = 9999999;
int A[MAX][MAX];

vector<pair<int,int> > willBeEdit;
bool check(int x, int y)
{
    if(x>0 && y>0) //右下角
    {
        if( A[x][y] + A[x-1][y-1] > A[x-1][y]+A[x][y-1] ) return false;
    }
    if(x<n-1 && y>0) //左下角
    {
        if( A[x][y] + A[x+1][y-1] < A[x+1][y]+A[x][y-1] ) return false;
    }
    if(x<n-1 && y<n-1 ) //左上角
    {
        if( A[x][y] + A[x+1][y+1] > A[x+1][y] + A[x][y+1] ) return false;
    }
    if(x>0 && y< n-1 ) //右上角
    {
        if( A[x][y] + A[x-1][y+1] < A[x-1][y] + A[x][y+1] ) return false;
    }
    return true;
}
bool edit()
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<m-1;j++)
        {
            if(A[i][j]+A[i+1][j+1] > A[i+1][j]+A[i][j+1])
                willBeEdit.push_back(make_pair(i,j));
        }
    }
    //Edit
    //确定范围
    for(int i=0; i<willBeEdit.size();i++)
    {
        int x = willBeEdit[i].second; int y = willBeEdit[i].first;
        if(check(x,y)) continue;
        int lo = INF_LO; int hi = INF_HI;
        if(x>0 && y>0) //右下角
        {
            if( hi+A[x-1][y-1] > A[x-1][y]+A[x][y-1] ) hi = A[x-1][y] + A[x][y-1] - A[x-1][y-1];
        }
        if(x<n-1 && y>0) //左下角
        {
            if( lo+A[x+1][y-1] < A[x+1][y]+A[x][y-1] ) lo = A[x+1][y] + A[x][y-1] - A[x+1][y-1];
        }
        if(x<n-1 && y<n-1 ) //左上角
        {
            if( hi + A[x+1][y+1] > A[x+1][y] + A[x][y+1] ) hi = A[x+1][y] + A[x][y+1] -A[x+1][y+1];
        }
        if(x>0 && y< n-1 ) //右上角
        {
            if( lo + A[x-1][y+1] < A[x-1][y] + A[x][y+1] ) lo = A[x-1][y] + A[x][y+1] -A[x-1][y+1];
        }
        if( lo>=hi ) return false;
        else
        {
            A[x][y]=lo+1+(hi-lo-2)*rand();
        }
        return true;
    }
}
int main()
{
    while(cin>>m>>n)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                cin>>A[j][i];
        }
        if(edit())
        {
            cout<<"Succeed"<<endl;

        }
        else cout<<"Failed"<<endl;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cout<<A[j][i]<<' ';
            }
            cout<<endl;
        }
    }
}