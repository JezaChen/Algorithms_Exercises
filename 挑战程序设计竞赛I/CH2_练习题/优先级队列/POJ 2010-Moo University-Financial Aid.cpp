#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
//pair<int,int> Cow; //first: scores, second: money
static const int N_MAX = 20000;
int N,C;
void solve()
{
    int F;
    cin>>N>>C>>F;
    int half = N/2;
    pair<int,int> Cow[C];
    for(int i=0;i<C;i++)
    {
        //cin>>Cow[i].first>>Cow[i].second;
        scanf("%d %d",&Cow[i].first,&Cow[i].second);
    }
    sort(Cow,Cow+C); //按照成绩对牛进行排序
    int moneyOfLower[C], moneyOfHigher[C]; //维护（排序后）以牛i为中点的左右（成绩比它低、成绩比它高）两集合的最小money
    //代码块1
    {
        priority_queue<int> PQ; //优先级队列，最大长度限制在N的一半，若超过则剔除money最多的那一位
        int total = 0; //队列元素money之和
        for (int i = 0; i < C; i++)
        {
            moneyOfLower[i] = (PQ.size() == half ? total : 0x3f3f3f3f); //如果队列的元素数还没到N的一半，该牛的左集合的money数为正无穷，其实也就是不符合题意
            PQ.push(Cow[i].second);
            total += Cow[i].second;
            if (PQ.size() > half) //如果超了
            {
                //剔除money最高的那一位
                total -= PQ.top();
                PQ.pop();
            }
        }
    }
    //从而得出的左集合是花钱最小的而且成绩都比牛i低的牛的集合
    
    {
        priority_queue<int> PQ;
        int total = 0;
        for (int i = C-1; i >= 0; i--)
        {
            moneyOfHigher[i] = (PQ.size() == half ? total : 0x3f3f3f3f);
            PQ.push(Cow[i].second);
            total += Cow[i].second;
            if (PQ.size() > half)
            {
                total -= PQ.top();
                PQ.pop();
            }
        }
    }

    int ans = -1;
    for(int i=C-1; i>=0; i--) //倒过来寻找最大的中位数
    {
        if( Cow[i].second + moneyOfHigher[i] + moneyOfLower[i] <= F)
        {
            ans = Cow[i].first; break;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    solve();
}
