#include <iostream>
#include <algorithm>
#define INF -1
using namespace std;
static const int MAX=100002;
//用左孩子右兄弟表示法
struct Node
{
    //int Num;
    int parent;
    int left_child;
    int right_brother;
    int depth;
};
Node nodes[MAX];

void print(int u)
{
    cout<<"node "<<u<<": ";
    cout<<"parent = "<<nodes[u].parent<<", ";
    cout<<"depth = "<<nodes[u].depth<<", ";
    if(nodes[u].parent==INF) cout<<"root, ";
    else if(nodes[u].left_child==INF) cout<<"leaf, ";
    else cout<<"internal node, ";

    cout<<"[";
    int child=nodes[u].left_child;
    while(1)
    {
        if(child==INF) break;
        else cout<<child<<",";

        child=nodes[child].right_brother;
    }
    if(nodes[u].left_child==INF) cout<<']';
    cout<<"\b]";
    cout<<endl;
}

void Solve_depth(int u,int depth) //递归求深度
{
    nodes[u].depth=depth;
    if(nodes[u].right_brother!=INF) Solve_depth(nodes[u].right_brother,depth); //递归求兄弟的深度
    if(nodes[u].left_child!=INF) Solve_depth(nodes[u].left_child,depth+1); //递归求孩子的深度
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        nodes[i].parent=nodes[i].left_child=nodes[i].right_brother=INF;
        nodes[i].depth=0;
    }
    for(int i=0;i<n;i++)
    {
        int j,child_num;
        cin>>j>>child_num;
        int temp=INF;
        for(int k=0;k<child_num;k++)
        {
            int u;
            cin>>u;
            nodes[u].parent=j;
            if(k==0) nodes[j].left_child=u; //这句容易漏
            if(temp!=INF) nodes[temp].right_brother=u;
            temp=u;
        }
    }
    int root;
    for(int i=0;i<n;i++)
        if(nodes[i].parent==INF) {root=i;break;}

    Solve_depth(root,0);
    for(int i=0;i<n;i++) print(i);
}