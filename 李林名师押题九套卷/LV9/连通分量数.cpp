#include <iostream>
using namespace std;

#define NONE -1

class Graph {
public:
    Graph(int N) {
        V = N;
        visited = new bool[N];
        adjacencyMatrix = new int*[V];
        for(int i = 0; i< V; i++){
            adjacencyMatrix[i] = new int [V];
            //init
            for(int j=0; j<V; j++)
                adjacencyMatrix[i][j] = NONE;
            visited[i] = false;
        }
    }
    void add_edge(int v1, int v2) {
        adjacencyMatrix[v1 - 1][v2 - 1] = 1;
    }

    unsigned int num_connected_components()
    {
        unsigned int ans = 0;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                ans++;
                dfs(i);
            };
        }
        return ans;
    }
    int V,E;
    int** adjacencyMatrix;
    bool* visited;
private:
    void dfs(int u){
        visited[u] = true;
        for(int v = 0; v < V; v++){
            if(adjacencyMatrix[u][v] != NONE && !visited[v])
                dfs(v);
        }
    }
};

int main() {
    int M;
    cin>>M;
    while(M--) {
        int N, C;
        cin>>N>>C;

        Graph graph(N);
        //读取每一条边
        for(int i=0;i<C;i++) {
            int v1, v2;
            cin>>v1>>v2;
            graph.add_edge(v1, v2);
        }
        //输出这个图的连通分量的数量
        cout << graph.num_connected_components() << endl;

    }
    return 0;
}
