#include <iostream>
#include <queue>
#include <vector>

using namespace std;

static const int ML_MAX = 10000;
static const int MD_MAX = 10000;
static const int N_MAX = 1001;
static const int INF = (1<<21);

int N,ML,DL;
bool inQueue[N_MAX];
queue<int> Q;
int d[N_MAX];
struct conncet
{
    int A,B,D;
};
struct edge
{
    int v,cost;
};
vector<edge> G[N_MAX]; //邻接表
int SPFA(int s)
{
    //init
    fill(inQueue,inQueue+N,false);
    fill(d,d+N,INF);
    int cnt[N];
    fill(cnt,cnt+N,0);

    d[s]=0;
    Q.push(s);
    cnt[0]++;
    inQueue[s]=true;
    while(!Q.empty())
    {
        int u = Q.front(); Q.pop();
        inQueue[u] = false;
        for(int i=0;i<G[u].size();i++)
        {
            int v = G[u][i].v;
            int cost = G[u][i].cost;
            if(d[v] > d[u] + cost)
            {
                d[v] = d[u] +cost ; //作松弛
                if(inQueue[v]==false) //入队
                {
                    if(++cnt[v]>N)
                        return -1;
                    Q.push(v);
                    inQueue[v]=true;
                }
            }
        }
    }

    int res = d[N-1];
    if(res==INF) return -2;
    return res;
}
void solve()
{
    cin>>N>>ML>>DL;
    for(int i=0;i+1<N;i++)
   //     G[i].push_back(edge{i+1,0}); //情况一加边
        G[i+1].push_back(edge{i,0});
    int a,b,d;
    for(int i=0;i<ML;i++)
    {
        cin>>a>>b>>d;
        G[a-1].push_back(edge{b-1,d}); //情况二加边
    }
    for(int i=0;i<DL;i++)
    {
        cin>>a>>b>>d;
        G[b-1].push_back(edge{a-1,-d}); //情况三加边
    }
    cout<<SPFA(0)<<endl;
}
int main()
{
    solve();
}
