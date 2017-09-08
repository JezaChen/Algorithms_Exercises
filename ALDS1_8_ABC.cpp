#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class BinNode
{
public:
    int data;
    BinNode* parent,*left_child,*right_child;
    BinNode(int d=-1,BinNode* p=NULL,BinNode* l=NULL,BinNode* r=NULL):data(d),parent(p),left_child(l),right_child(r){}
    BinNode* insertAsLc(int u)
    {
        return left_child=new BinNode(u,this);
    }
    BinNode* insertAsRc(int u)
    {
        return right_child=new BinNode(u,this);
    }
    BinNode* succ() //中序遍历的直接后继
    {
        if(right_child) //如果有右孩子
        {
            BinNode* u=right_child;
            while(u->left_child)
            {
                u=u->left_child; //不断沿左分支深入
            }
            return u;
        }
        else //如果没有右孩子，则找到包含它为左子树结点的最低祖先
        {
            BinNode* u=this;
            BinNode* p=u->parent;
            while(u!=p->right_child)
            {
                u=p;
                p=p->parent;
            }
            return p; //返回该最低祖先
        }
    }
};
void printNode(BinNode* u)
{
    cout<<" "<<u->data;
}
class BST
{
    BinNode* _root;
    BinNode* _hot;
public:
    BST() {_root=_hot=NULL;}
    bool remove(BinNode*& u);
    BinNode*& search(int u);
    BinNode*& searchIn(BinNode* p,int u,BinNode*& hot);
    BinNode* insert(int u);
    bool del(int u);
    void visitLeftbranch(BinNode* u,stack<BinNode*>& S);
    void print_preOrder(); //前序遍历输出
    void print_inOrder(); //中序遍历输出
};
BinNode*& BST::searchIn(BinNode* p,int u,BinNode*& hot)
{
    if(p==NULL) return hot; //递归基
    hot=p; //标记_hot节点
    if(p->data==u) return p;
    return searchIn((u<p->data?p->left_child:p->right_child),u,hot); //递归实现
}

BinNode*& BST::search(int u)
{
    BinNode* hot=NULL;
    BinNode* t=searchIn(_root,u,hot);
    return t;
   // if(t) return t;
   // return hot; //如果不存在该值，则返回最后一个经过的结点
}

BinNode* BST::insert(int u)
{
    if(!_root) return _root=new BinNode(u); //空树就插入作为根结点
    BinNode* t=search(u);
    if(t->data==u) return t; //要保证相应的结点不存在
    return (u<t->data?t->insertAsLc(u):t->insertAsRc(u)); //实现插入
}
bool BST::remove(BinNode *&u) //u必须保证是叶子
{
    if(u)
    {  //切断与父亲的联系
       // u == u->parent->left_child ? (u->parent->left_child = NULL) : (u->parent->right_child = NULL);
       // u->parent = NULL;
       //备注：在二叉搜索树的删除操作中已经切断了与父亲的联系
        delete u;
        u=NULL;
        return true;
    }
    return false;
}
bool BST::del(int x)
{
    BinNode*& u=search(x);
    BinNode* w=u;
    BinNode* succ=NULL; //实际删除位置的接替者
    if(u->data!=x) return false; //要保证结点存在

    //不存在双子树的情况下
    if(!u->left_child) //左子树不存在的情况下
    {
        succ=u->right_child;
        (u->parent->left_child==u)?(u->parent->left_child=succ):(u->parent->right_child=succ);
    }
    else if(!u->right_child) //右子树不存在的情况下
    {
        succ=u->left_child;
        (u->parent->left_child==u)?(u->parent->left_child=succ):(u->parent->right_child=succ);
    }
    else //双子树的情况
    {
        w=w->succ(); //找到直接后继
        swap(w->data,u->data); //交换两者的数据
        BinNode* p=w->parent; //实际删除结点的父亲
        ((u==p)?(p->right_child):(p->left_child))=succ=w->right_child;
    }
    //解决接替者的后顾之忧
    _hot=w->parent; //记录实际被删除结点的父亲
    if(succ) //如果接替者不是空节点
        succ->parent=_hot; //那就认爹吧
    remove(w);
    return true;
}
void BST::visitLeftbranch(BinNode *u, stack<BinNode*> &S)
{
    while(u)
    {
        printNode(u); //先访问
        S.push(u->right_child); //右孩子入栈
        u=u->left_child;
    }
}
void BST::print_preOrder()
{
    BinNode* u=_root;
    stack<BinNode*> S;
    while(true)
    {
        visitLeftbranch(u,S);
        if(!S.empty()) {u=S.top();S.pop();}
        else break;
    }
}
void BST::print_inOrder()
{
    stack<BinNode*> S;
    BinNode* u=_root;
    while(true)
    {
        if(u)
        {
            S.push(u);
            u=u->left_child;
        }
        else if(!S.empty())
        {
            u=S.top();S.pop(); //弹出栈顶
            printNode(u);
            u=u->right_child; //转入右孩子
        }
        else break;
    }
}
int main()
{
    BST Tree;
    int order_num;
    char order[10];
    int target_num;
    cin>>order_num;
    for(int i=0;i<order_num;i++)
    {
        cin>>order;
        switch(order[0])
        {
            case 'i': cin>>target_num; Tree.insert(target_num);break;
            case 'p': Tree.print_inOrder();cout<<endl;
                      Tree.print_preOrder();cout<<endl;
                      break;
            case 'f': cin>>target_num;
                if(Tree.search(target_num)->data==target_num) cout<<"yes"<<endl;
                else cout<<"no"<<endl;
                break;
            case 'd': cin>>target_num;Tree.del(target_num);
                break;
        }
    }
}