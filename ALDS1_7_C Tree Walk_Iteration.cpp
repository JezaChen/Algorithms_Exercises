#include <iostream>
#include <algorithm>
#include <stack>
#define INF -1
#define MAX 26
using namespace std;
struct BinNode
{
    int parent;

    int left_child;
    int right_child;

};
BinNode nodes[MAX];
void print(int u)
{
    cout<<" "<<u;
}
//前序遍历迭代算法
void visit_Along_Left_Branch(int u,stack<int>& S)
{
    while(u!=INF)
    {
        print(u);
        S.push(nodes[u].right_child);
        u=nodes[u].left_child; //继续深入
    }
}

void PreOrder(int r)
{
    stack<int> S;
    while(true)
    {
        visit_Along_Left_Branch(r,S);
        if(S.empty()) break;
        r=S.top();S.pop();
    }
}

void InOrder(int r)
{
    stack<int> S;
    while(true)
    {
        if(r!=INF)
        {
            S.push(r);
            r=nodes[r].left_child;
        }
        else if(!S.empty())
        {
            r=S.top();S.pop();
            print(r);
            r=nodes[r].right_child; //转向右节点
        }
        else
            break;
    }
}

void gotoHLVFL(stack<int>& S)
{
    int x;
    while((x=S.top())!=INF)
    {
        if(nodes[x].left_child!=INF) //尽可能向左
        {
            if(nodes[x].right_child!=INF)
                S.push(nodes[x].right_child); //右孩子入栈
            S.push(nodes[x].left_child); //然后左孩子入栈
        }
        else
            S.push(nodes[x].right_child); //实在迫不得已，右孩子入栈，不管右孩子是不是空节点，若是空节点就结束循环
    }
    S.pop(); //弹出空节点
}

void PostOrder(int r)
{
    stack<int> S; //辅助栈
    if(r!=INF) S.push(r); //根节点入栈
    while(!S.empty())
    {
        if(S.top()!=nodes[r].parent) //若栈顶非当前节点之父
            gotoHLVFL(S); //此时应该在以其右兄为根的子树中，找到HLVFL
        r=S.top();S.pop();
        print(r);
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
        //认儿子
        nodes[j].left_child=lc;nodes[j].right_child=rc;
        //认爹
        if(lc!=INF) nodes[lc].parent=j;
        if(rc!=INF) nodes[rc].parent=j;
    }
    //找到根节点
    int root;
    for(int i=0;i<n;i++)
        if(nodes[i].parent==INF)
        {
            root=i; break;
        }
    cout<<"Preorder"<<endl;
    PreOrder(root);
    cout<<endl;
    cout<<"Inorder"<<endl;
    InOrder(root);
    cout<<endl;
    cout<<"Postorder"<<endl;
    PostOrder(root);
    cout<<endl;
}