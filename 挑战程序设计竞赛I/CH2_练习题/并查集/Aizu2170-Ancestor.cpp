#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
static const int N_MAX = 100010;
//DEFINE UNION FIND

int N;
int parent[N_MAX];
int Rank[N_MAX];

void init()
{
    for(int i=0;i<N;i++)
    {
        parent[i] = i;
        Rank[i] = 0;
    }
}

int find(int x)
{
    if( parent[x] != x ) return parent[x] = find(parent[x]);
    else return x;
}

void unite(int x, int y)
{
    int x_p = find(x);
    int y_p = find(y);
    if(x_p == y_p) return;
    if( Rank[x_p] < Rank[y_p] )
    {
        parent[x_p] = y_p;
    }
    else
    {
        parent[y_p] = x_p;
        if( Rank[x_p] == Rank[y_p] )
        {
            Rank[x_p]++;
        }
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

//END UNION_FIND

int tree_parent[N_MAX];
vector<int> tree_children[N_MAX];
int tree_ancestor[N_MAX];
bool tree_marked[N_MAX];

void bfs(int r)
{
    int theAncestor = r;
    int theIndex = r;

    queue<int> trav_index;
    queue<int> trav_ancestor;
    trav_ancestor.push(theAncestor); trav_index.push(r);

    while(!trav_index.empty())
    {
        theAncestor = trav_ancestor.front(); trav_ancestor.pop();
        theIndex = trav_index.front(); trav_index.pop();

        if(tree_marked[theIndex] == true)
        {
            theAncestor = theIndex;
        }

        tree_ancestor[theIndex] = theAncestor; //update
        //染色节点的祖先就是它本身

        //make its children follow its ancestor
        for(auto i = tree_children[theIndex].begin();i!=tree_children[theIndex].end();i++)
        {
            trav_index.push(*i); trav_ancestor.push(theAncestor); //先认这个祖先
        }
    }
}

void solve()
{
    int queryNums;
    while(cin>>N>>queryNums)
    {
        if (!N && !queryNums) return;
        init();
        for(int i=0;i<N;i++) { tree_children[i].clear(); tree_marked[i] = false; }

        int p;
        for (int i = 1; i < N; i++)
        {
            cin >> p;
            tree_parent[i] = --p;
            tree_children[p].push_back(i);
        }

        tree_marked[0] = true;
        stack<char> stackQueryChar;
        stack<int> stackQueryNum;
        //先进行染色操作，其他的先不管，到最后在一次性来个BFS，避免TLE
        char queryChar;
        int queryNum;
        for (int i = 0; i < queryNums; i++)
        {
            cin >> queryChar >> queryNum;
            --queryNum;
            if (queryChar == 'M')
            {
                if (!tree_marked[queryNum]) tree_marked[queryNum] = true;
                else continue; //记得跳过！！！
            }
            stackQueryChar.push(queryChar);
            stackQueryNum.push(queryNum); //要后置！！！
        }

        bfs(0);

        for (int i = 0; i < N; i++) {
            unite(i, tree_ancestor[i]); //紧紧围绕着祖先
        }
        //之后每个并查集的老大是决定性因素了，它的祖先就是该并查集所有元素的祖先

        //逆回来处理
        unsigned long long ans = 0; //ull
        while (!stackQueryChar.empty())
        {
            queryChar = stackQueryChar.top();
            stackQueryChar.pop();
            queryNum = stackQueryNum.top();
            stackQueryNum.pop();
            if (queryChar == 'Q')
            {
                ans += tree_ancestor[find(queryNum)] + 1; //加上那一团的老大的祖先
            }
            else //queryNum == 'M'
            {
                //执行逆向操作
                //去掉染色的节点之后的祖先是它父节点的祖先，从而再更新那一团并查集所有元素的祖先
                int newAncestor = tree_ancestor[find(tree_parent[queryNum])];
                unite(queryNum, tree_parent[queryNum]); //合并两团并查集
                tree_ancestor[find(queryNum)] = newAncestor;
            }
        }

        cout << ans << endl;
    }
}

int main()
{
    solve();
    return 0;
}
