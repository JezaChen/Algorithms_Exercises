#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>


using namespace std;
static const int C_MAX = 2501;
static const int S_MAX = 2501;
struct Cow
{
    int minSPF, maxSPF;
    friend bool operator < (const Cow& a, const Cow& b) { return a.maxSPF < b.maxSPF; }
    friend bool operator > (const Cow& a, const Cow& b) { return a.maxSPF > b.maxSPF; }
};

struct Lotion
{
    int SPF;
    int cover;
};

bool cowComp(const Cow& a, const Cow& b)
{
    return a.minSPF < b.minSPF; //注意是用minSPF来排序
}
bool lotionComp(const Lotion& a, const Lotion& b)
{
    return a.SPF < b.SPF;
}
vector<Lotion> vec_lotions;
vector<Cow> vec_cows;

int C,S;
int solve()
{
    //priority_queue<Lotion,vector<Lotion>,greater<Lotion> > lotions;
    priority_queue<Cow,vector<Cow>,greater<Cow> > cows;
    cin>>C>>S;
    Cow temp;
    Lotion temp2;
    for(int i=0;i<C;i++)
    {
        cin>>temp.minSPF>>temp.maxSPF;
        vec_cows.push_back(temp);
    }
    for(int i=0;i<S;i++)
    {
        cin>>temp2.SPF>>temp2.cover;
        vec_lotions.push_back(temp2);
    }
    //handle
    sort(vec_cows.begin(),vec_cows.end(),cowComp);
    sort(vec_lotions.begin(),vec_lotions.end(),lotionComp);

    int ans = 0; int cur = 0;
    for(int i=0;i<vec_lotions.size();i++)
    {
        while(cur<C && vec_cows[cur].minSPF <= vec_lotions[i].SPF)
        {
            cows.push(vec_cows[cur]); //fuck, it is cur not i
            cur++; //fuck, cur++ should behind the previous sentence
        }

        while(!cows.empty() && vec_lotions[i].cover > 0 )
        {
            Cow cowSelected = cows.top(); cows.pop();
            if(cowSelected.maxSPF >= vec_lotions[i].SPF)
            {
                ans++;
                vec_lotions[i].cover--;

            }
            //else break; //? Is Okay
        }
    }

    return ans;
}

int main()
{
    cout<<solve()<<endl;
    return 0;
}
