#include <iostream>
using namespace std;
class Node {
public:
    Node(int elem, Node *left=NULL, Node *right=NULL) {
        this->elem = elem;
        this->left = left;
        this->right = right;
    }
    int elem;
    Node *left, *right;
};
class Tree {
public:
    Tree() {
        root = NULL;
    }
    void insert(int elem) {
        if(root == NULL){
            root = new Node(elem);
        }
        else
            insertHelp(root, elem);
    }
    void traverse(int *result) {
        int k = -1;
        inTrav(root, result, k);
    }
    Node *root;
private:
    Node* insertHelp(Node* subRoot, int elem){
        if(subRoot == NULL){
            return new Node(elem);
        }
        if(elem < subRoot -> elem){
            subRoot->left = insertHelp(subRoot->left, elem);
        }
        else
            subRoot->right = insertHelp(subRoot->right, elem);

        return subRoot;
    }

    void inTrav(Node *subRoot, int* result, int& k){
        if(subRoot == NULL) return;
        
        inTrav(subRoot->left, result, k);
        result[++k] = subRoot->elem;
        inTrav(subRoot->right, result, k);
    }
};
int main() {
    int M;
    cin>>M;
    while(M--) {
        int N;
        cin>>N;
        //读取输入
        Tree tree;
        for(int i=0;i<N;i++) {
            int temp;
            cin>>temp;
            tree.insert(temp);
        }
        //遍历这棵树
        int *result = new int[N];
        tree.traverse(result);
        //输出结果
        for(int i=0; i<N; i++)
            cout << result[i] << (i==N-1?'\n':' ');
        delete [] result;
    }
    return 0;
}
