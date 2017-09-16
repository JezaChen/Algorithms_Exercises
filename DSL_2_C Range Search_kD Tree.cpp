#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

class Node  //节点
{
public:
    int location;
    int p,l,r;
    Node() {}
};

class Point
{
public:
    int id,x,y;
    Point() {}
    Point(int id, int x,int y):id(id),x(x),y(y) {}
    bool operator < (const Point& p)const {return id<p.id; }

    void print()
    {
        printf("%d\n",id);
    }
};

static const int MAX = 1000000;
static const int NIL = -1;

int N; //节点数目
Point P[MAX]; //点集，下标是节点编号
Node T[MAX]; //节点编号集，顺序服从前序遍历，其实这个就是kd树的主体
int np;
//排序所要用到的函数
bool lessX(const Point& x, const Point& y) {return x.x<y.x;}
bool lessY(const Point& x, const Point& y) {return x.y<y.y;}

int makeKDTree(int l,int r,int depth)
{
    if(l>=r) return NIL;
    int mid = (l+r)>>1;
    int t=np++; //节点编号自增
    if(depth%2==0) //偶数高度，排序x
       sort(P+l,P+r,lessX);
    else sort(P+l,P+r,lessY); //奇数高度，排序y
    T[t].location=mid;
    //递归构建左子树和右子树
    T[t].l=makeKDTree(l,mid,depth+1);
    T[t].r=makeKDTree(mid+1,r,depth+1); //mmp

    return t; //记得返回构建后子树的根节点编号
}

void find(int v,int sx,int tx,int sy,int ty,int depth,vector<Point> &ans)
{
    int x=P[T[v].location].x;
    int y=P[T[v].location].y;

    if(sx<=x && x<=tx && sy<=y && y<=ty)  ans.push_back(P[T[v].location]);

    if(depth%2==0) //偶数高度，根据x寻找左右子树
    {
        if (T[v].l != NIL) {
            if (sx <= x) find(T[v].l, sx, tx, sy, ty, depth + 1, ans);
        }
        if (T[v].r != NIL) {
            if (x <= tx) find(T[v].r, sx, tx, sy, ty, depth + 1, ans);
        }
    }
    else  //奇数高度，根据y寻找左右子树
    {
        if(T[v].l!=NIL)
        {
            if(sy<=y) find(T[v].l,sx,tx,sy,ty,depth+1,ans);
        }
        if(T[v].r!=NIL)
        {
            if(y<=ty) find(T[v].r,sx,tx,sy,ty,depth+1,ans);
        }
    }
}

int main()
{
    int x,y;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d %d",&x,&y);
        P[i]=Point(i,x,y); //create
        T[i].l=T[i].r=T[i].p=NIL; //init
    }

    np=0; //init
    int root=makeKDTree(0,N,0); //构建kd树，获取根节点

    int q;
    scanf("%d",&q);
    int sx,tx,sy,ty;
    vector<Point> ans;
    for(int i=0;i<q;i++)
    {
        scanf("%d %d %d %d",&sx,&tx,&sy,&ty);
        ans.clear(); //init
        find(root,sx,tx,sy,ty,0,ans); //从根节点开始检索
        sort(ans.begin(),ans.end());
        for(int j=0;j<ans.size();j++)
        {
            ans[j].print();
        }
        printf("\n");
    }

    return 0;
}