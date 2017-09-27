#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>


using namespace std;

typedef struct
{
    int key;
    int value;
} Elem;

void pemute (vector <Elem>& V)
{
    int n = V.size();
    srand(time(NULL));
    for(int i=0; i<n; i++)
    {
        swap(*(V.begin()+i),*(V.begin()+ rand()% (n)));
    }
}
int main()
{
    int n;
    while(cin>>n)
    {
        vector<Elem> V;
        int r;
        for(int i=0; i<n; i++)
        {
            Elem r;
            cin>>r.value;
            V.push_back(r);
        }
        pemute(V);
        for(int i=0; i<V.size(); i++)
            cout<<V[i].value<<" ";
        cout<<endl;
    }

}