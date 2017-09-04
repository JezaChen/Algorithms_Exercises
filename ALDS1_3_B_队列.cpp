#include <iostream>
#include <cstring>
#define LEN 100001
using namespace std;
typedef struct pp
{
    int time;
    char name[100];
}P;

P QUEUE[LEN];
int head=0,tail=0,n=0; //头指针、尾指针、数目

void enqueue(P New_Member)
{
   QUEUE[tail]=New_Member;
   tail=(tail+1)%LEN;
}

P dequeue()
{
    P x=QUEUE[head];
    head=(head+1)%LEN;
    return x;
}
bool isEmpty()
{
    return (head==tail);
}

int main() {

    int Handle_Time;
    int Whole_Time=0;
    cin>>n>>Handle_Time;
    for(int i=0;i<n;i++)
    {
        char Name[100]; int t;
        cin>>Name>>t;
        P x;
        strcpy(x.name,Name);
        x.time=t;
        enqueue(x);
    }

    while(!isEmpty())
    {
        P x=dequeue();
        if(x.time>Handle_Time)
        {
            x.time-=Handle_Time; //减去处理时间
            Whole_Time+=Handle_Time;
            enqueue(x); //重新入队
        }
        else
        {
            Whole_Time+=x.time;
            cout<<x.name<<' '<<Whole_Time<<endl;
        }
    }
}
