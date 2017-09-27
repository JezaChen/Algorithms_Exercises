#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int search (vector <int> V, int target)
{
    int n = V.size();
    bool visited[n];
    for(int i=0;i<n;i++) visited[i]=false;
    srand(time(NULL));
    int pick = 0;
    while(pick < n)
    {
        int s = rand() % n;
        if(visited[s]) continue;
        if(V[s]==target) return s;
        pick++;
    }
    return -1 ;
}
int main()
{
    int n;
    while(cin>>n)
    {
        cout<<"INPUT AN ARRAY"<<endl;
        int r; vector<int> V;
        for(int i = 0; i< n; i++)
        {
            cin>>r;
            V.push_back(r);
        }
        cout<<"SEARCH: ";
        cin>>r;
        int result;
        if((result=search(V,r))==-1)
        {
            cout<<"NO SUCH ELEMENT YOU WANT TO SEARCH "<<endl;
        }
        else
        {
            cout<<"SUCCEED: "<<result<<endl;
        }
    }
}