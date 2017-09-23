#include <iostream>
#include <algorithm>
#define INF -1
#define MAX 26
using namespace std;
struct BinNode
{
    int parent;

    int left_child;
    int right_child;

    int height;
    int depth;
};

BinNode nodes[MAX];
void Set_Depth(int x,int d)
{
    nodes[x].depth=d;
    if(nodes[x].left_child!=INF) Set_Depth(nodes[x].left_child,d+1);
    if(nodes[x].right_child!=INF) Set_Depth(nodes[x].right_child,d+1); //递归实现
}

int Set_Height(int x)
{
    //也可以通过递归实现
    if(x==INF) return -1; //递归基，空节点
    return nodes[x].height=max(Set_Height(nodes[x].left_child),Set_Height(nodes[x].right_child))+1; //深入递归
}

void print(int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"node "<<i<<": ";
        cout<<"parent = "<<nodes[i].parent<<", ";
        cout<<"sibling = "<<(nodes[i].parent!=INF?(i==nodes[nodes[i].parent].left_child?nodes[nodes[i].parent].right_child:nodes[nodes[i].parent].left_child):(-1))<<", ";
        cout<<"degree = "<<(nodes[i].left_child==INF?(nodes[i].right_child==INF?0:1):(nodes[i].right_child==INF)?1:2)<<", ";
        cout<<"depth = "<<nodes[i].depth<<", ";
        cout<<"height = "<<nodes[i].height<<", ";
        cout<<(nodes[i].parent==INF?("root"):((nodes[i].left_child==INF&&nodes[i].right_child==INF)?"leaf":"internal node"));
        cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) nodes[i].parent=nodes[i].left_child=nodes[i].right_child=INF;
    for(int i=0;i<n;i++)
    {
        int j,lc,rc;
        cin>>j>>lc>>rc;
        nodes[j].left_child=lc;nodes[j].right_child=rc;  //认儿子
        nodes[lc].parent=j; nodes[rc].parent=j; //认爹
    }
    int root=0;
    for(int i=0;i<n;i++)
        if(nodes[i].parent==INF)
        {root=i;break;}
    Set_Height(root);
    Set_Depth(root,0);
    print(n);
}