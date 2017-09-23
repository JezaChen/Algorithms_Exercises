#include <iostream>
#include <vector>

using namespace std;
class DisjointSet
{
public:
    vector<int> rank,p; //rank为树高, p为父节点

    DisjointSet() {}
    DisjointSet(int size) {
        //init
        rank.resize(size, 0);
        p.resize(size, 0);
        for (int i = 0; i < size; i++) {
            p[i] = i;
            rank[i] = 0;
        }
    }
    bool same(int x,int y) { return findSet(x)==findSet(y);}
    void unite(int x,int y) { link(findSet(x),findSet(y)); }
    void link(int x,int y)
    {
        rank[x]>rank[y]?p[y]=x:p[x]=y;
        if(rank[x]==rank[y]) rank[y]++;
    }

    int findSet(int x)
    {
        int r=x;
        while(p[r]!=r)
            r=p[r];

        return r;
    }
};
int main()
{
    int n,q;
    cin>>n>>q;
    DisjointSet ds(n);
    for(int i=0;i<q;i++)
    {
        int order,x,y;
        cin>>order>>x>>y;
        switch(order)
        {
            case 0: ds.unite(x,y);break;
            case 1: cout<<(ds.same(x,y)?1:0)<<endl;break;
        }
    }
}