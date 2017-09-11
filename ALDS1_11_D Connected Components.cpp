#include <iostream>
#include <vector>
#include <queue>
static const int MAX=100000;
using namespace std;

vector<int> follow[MAX];
int color[MAX];  //-1 represent No Visited

void bfs(int i,int c)
{
    queue<int> Q;
    Q.push(i);color[i]=c;
    while(!Q.empty())
    {
        int p=Q.front();Q.pop();
        for(int j=0;j<follow[p].size();j++)
        {
            if(color[follow[p][j]]!=-1) continue;
            //else
            Q.push(follow[p][j]); color[follow[p][j]]=color[p];
    }
}

int main()
{
   int n,m;
   cin>>n>>m;
   for(int i=0;i<n;i++) color[i]=-1;
   for(int i=0;i<m;i++)
   {
       int a,b;
       cin>>a>>b;
       follow[a].push_back(b);
       follow[b].push_back(a);
   }
   int c=0;
   for(int i=0;i<n;i++)
   {
       if(color[i]==-1)
       {
           bfs(i, c);
           c++;
       }
   }
   int order_num;cin>>order_num;
   for(int i=0;i< order_num;i++)
   {
       int a,b;
       cin>>a>>b;
       if(color[a]==color[b]) cout<<"yes"<<endl;
       else cout<<"no"<<endl;
   }
}