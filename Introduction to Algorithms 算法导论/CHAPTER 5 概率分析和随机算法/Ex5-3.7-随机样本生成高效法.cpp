#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>


using namespace std;

static const int MAX = 99999;
bool IN[MAX];

typedef struct
{
    int key;
    int value;
} Elem;

vector<Elem> randomSample (vector<Elem>& V, int m, int n)
{
    vector<Elem> S;
    if(m==0) return S;
    else
    {
        S = randomSample(V, m-1, n-1);
        int i = rand() % n;
        if(IN[i]==true)
        {
            S.push_back(V[n]);
            IN[n] = true;
        }
        else
        {
            S.push_back(V[i]);
            IN[i] = true;
        }
    }
    return S;
}
int main()
{
    srand(time(NULL));
    int n;
    int m;
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++) IN[i] = false;
        vector<Elem> V;
        int r;
        for(int i=0; i<n; i++)
        {
            Elem r;
            cin>>r.value;
            V.push_back(r);
        }
        vector<Elem> S = randomSample(V, m, n-1);
        for(int i = 0; i < m;i++)
        {
            cout<<S[i].value<<' ';
        }
        cout<<endl;
    }

}