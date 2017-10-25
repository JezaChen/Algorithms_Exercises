#include <iostream>

using namespace std;
static const int N_MAX = 2010;
static const int M_MAX = 10010;
int parent[M_MAX];
int Rank[M_MAX];
int N,M;

void init()
{
	for(int i=0;i<M;i++)
	{
		parent[i] = i;
		Rank[i] = 0;
	}
}

int find(int x)
{
	if( parent[x] != x ) return find(parent[x]);
	else return x;
}

void unite(int x, int y)
{
	int x_p = find(x);
	int y_p = find(y);
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

void solve()
{
	int N,M;
	cin>>N>>M;

}
