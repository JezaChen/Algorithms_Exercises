#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

stack<int> T; //储存横坐标的栈
stack<pair<int,int>> R;

vector<int> r;
int main() {
    char str[20001];
    cin>>str;
    int result=0;
    bool completed=false;
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='\\') //入栈
        {
            T.push(i);
        }
        else if(str[i]=='/'&&!T.empty()) //出栈，比对
        {
            int x=T.top(); T.pop();
            int a=i-x; //计算该行面积
            while(!R.empty()&&R.top().first>x)  //若包含
            {
                a+=R.top().second; R.pop();  
            }
            if(a)
               R.push(make_pair(x,a)); //重新入栈
        }

    }
    int sum=0;
    while(!R.empty())
    {
        sum+=R.top().second;
        r.push_back(R.top().second); R.pop();
    }
    cout<<sum<<endl;
    cout<<r.size();
    for(int i=r.size()-1;i>=0;i--)
        cout<<' '<<r[i];
    cout<<endl;
}