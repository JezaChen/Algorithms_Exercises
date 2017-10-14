#include <iostream>
#include <vector>
using namespace std;

static const int ML_MAX = 10000;
static const int MD_MAX = 10000;
static const int N_MAX = 1001;
static const int INF = (1<<21);
struct connect
{
    int A,B,D;
};
vector<connect> MLGroup;
vector<connect> DLGroup;
int N,ML,MD;
int d[N_MAX];

int solve()
{
    fill(d,d+N,INF); //init
    d[0]=0;
    //Bellman-Ford
    for(int k=0;k<N;k++)
    {
        //情况一，按编号排序
        for(int i=0;i+1<N;i++)
        {
            if(d[i+1]!=INF)
            {
                d[i] = min (d[i],d[i+1]);
            }
        }
        //情况二，关系好的牛拉近距离
        for(int i=0;i<MLGroup.size();i++)
        {
            if(d[MLGroup[i].A-1] != INF)
            {
                d[MLGroup[i].B-1] = min(d[MLGroup[i].B-1],d[MLGroup[i].A-1]+MLGroup[i].D);
            }
        }
        //情况三，关系不好的牛拉远距离
        for(int i=0;i<DLGroup.size();i++)
        {
            if(d[DLGroup[i].B-1]!=INF)
            {
                d[DLGroup[i].A-1] = min(d[DLGroup[i].A-1],d[DLGroup[i].B-1]-DLGroup[i].D);
            }
        }
    }

    int res = d[N-1];
    if(d[0]<0) return -1;
    if(res==INF) return -2;

    return res;
}
int main()
{
    int ML,DL;
    cin>>N>>ML>>DL;
    connect temp;
    for(int i=0;i<ML;i++)
    {
        cin>>temp.A>>temp.B>>temp.D;
        MLGroup.push_back(temp);
    }
    for(int i=0;i<DL;i++)
    {
        cin>>temp.A>>temp.B>>temp.D;
        DLGroup.push_back(temp);
    }
    cout<<solve()<<endl;
}
