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

    void sizes_of_connected_components(int *result, int &result_size) {
        result_size = 0;
        int num;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                num = 0;
                dfs(i, num);
                result[result_size++] = num;


                int j = result_size - 2;
                while(j >= 0){
                    if(result[j] < num) break;
                    swap(result[j], result[j+1]);
                    j--;
                }
            };
        }
    }
    int V,E;
    int** adjacencyMatrix;
    bool* visited;
private:
    void dfs(int u, int& num){
        visited[u] = true;
        num++;
        for(int v = 0; v < V; v++){
            if(adjacencyMatrix[u][v] != NONE && !visited[v])
                dfs(v, num);
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
        //求出这个图每个连通分量的大小并从小到大输出
        int *result = new int[N];
        int result_size;
        graph.sizes_of_connected_components(result, result_size);
        for(int i=0; i<result_size; i++)
            cout << result[i] << (i==result_size-1?'\n':' ');

    }
    return 0;
}
