#include <iostream>
#include <vector>
#include <algorithm>
#define In_Heap(n,i)  ((-1)<(i))&&((i)<(n)) //判断PQ[i]是否合法
#define lt(i,j) ((i)>(j)) //优先级，目前取大者优先
#define Parent(i)  ((i-1)>>1) //求父节点
#define Last_Internal(n)  Parent(n-1) //最后一个内部节点，也就是末节点的父亲
#define LChild(i) (((i)<<1)+1) //左孩子
#define RChild(i) ((1+(i))<<1) //右孩子
#define Parent_Valid(i) (0<i) //节点i是否有父亲，只要不是根节点都是有父亲的
#define LChildValid(n,i)   In_Heap(n,LChild(i)) //判断节点i是否有左孩子
#define RChildValid(n,i)    In_Heap(n,RChild(i)) //判断节点i是否有右孩子
#define Bigger(PQ,i,j)  (lt(PQ[i],PQ[j])?i:j) //判断优先者
#define ProperParent(PQ,n,i) \
((RChildValid(n,i))?((LChildValid(n,i))?\
Bigger(PQ,Bigger(PQ,i,LChild(i)),RChild(i)):Bigger(PQ,i,RChild(i))):\
((LChildValid(n,i))?Bigger(PQ,i,LChild(i)):(i)))//用于Floyd算法，求该节点以及两个孩子间的最大者


using namespace std;
class Heap
{
public:
    vector<int> V;
    int percolate_Up(int pos); //上滤算法
    int percolate_Down(int pos); //下滤算法
    //上下滤算法的返回值是最终的位置
    void insert(int u); //插入操作
    int del_Max(int u); //删除最值
    int get_Max() {return V[0];} //获取最大/最小值
    void heapify(); //建堆算法
};

int Heap::percolate_Up(int pos) //上滤算法
{
    while(Parent_Valid(pos)) //只要节点仍有父亲
    {
        int parent_pos=Parent(pos); //记录父亲节点的位置
        if(lt(V[parent_pos],V[pos])) break; //只要顺序对了，就跳出循环
        swap(V[parent_pos],V[pos]); //否则交换位置，继续下一轮的循环
        pos=parent_pos; //更新当前节点的位置
    }
    return pos;
}

int Heap::percolate_Down(int pos) //下滤算法
{
    int j; //临时变量
    while(pos!=(j=ProperParent(V,V.size(),pos))) //如果最适合的父亲不是当前节点，则需要做一次下滤操作
    {
        swap(V[pos],V[j]); //交换位置
        pos=j; //更新当前节点的位置
    }
    return pos;
}

void Heap::insert(int u)
{
    V.push_back(u); //往后面追加u
    percolate_Up(V.size()-1); //进行一次上滤操作
}

int Heap::del_Max(int u)
{
    int temp=V[0];
    swap(V[0],V[V.size()-1]); //根节点和末节点交换位置
    V.pop_back(); //弹出末节点，相当于删除了原先的头结点
    percolate_Down(0); //对头结点进行下滤操作
    return temp;

}

void Heap::heapify() //Floyd建堆
{
    for(int i=Last_Internal(V.size());In_Heap(V.size(),i);i--)
    {
        percolate_Down(i); //对于每一个内部节点都进行一次下滤操作
    }
}

int main()
{
    int n;
    while(cin>>n)
    {
        Heap heap;
        for(int i=0;i<n;i++)
        {
            int j;cin>>j;
            heap.V.push_back(j);
        }
        heap.heapify();
        for(int i=0;i<n;i++)
            cout<<" "<<heap.V[i];
        cout<<endl;
    }
}