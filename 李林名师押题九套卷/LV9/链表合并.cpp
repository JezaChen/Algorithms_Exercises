#include <iostream>
using namespace std;
class Node {
public:
    Node(int elem=0, Node *next=NULL) {
        this->elem = elem;
        this->next = next;
    }
    int elem;
    Node *next;
};
class List{
public:
    List() {
        head = tail = NULL;
    }
    void append(int elem) {
        if(head == NULL){
            head = tail = new Node(elem);
        }
        else
            tail = tail->next = new Node(elem);
    }
    Node *head, *tail;
};
void merge(List &list1, List &list2, List &merged) {
    Node *list1_point = list1.head, *list2_point = list2.head;
    while(list1_point != NULL && list2_point != NULL){
        if(list1_point->elem < list2_point->elem){
            merged.append(list1_point->elem);
            list1_point = list1_point->next;
        }
        else{
            merged.append(list2_point->elem);
            list2_point = list2_point->next;
        }
    }

    while(list1_point != NULL){
        merged.append(list1_point->elem);
        list1_point = list1_point->next;
    }

    while(list2_point != NULL){
        merged.append(list2_point->elem);
        list2_point = list2_point->next;
    }
}
int main() {
    int M;
    cin>>M;
    while(M--) {
        int N1, N2;
        cin>>N1>>N2;
        //读取输入
        List list1, list2;
        for(int i=0; i<N1; i++) {
            int temp;
            cin>>temp;
            list1.append(temp);
        }
        for(int i=0; i<N2; i++) {
            int temp;
            cin>>temp;
            list2.append(temp);
        }
        //合并两个链表
        List merged;
        merge(list1, list2, merged);
        //输出合并结果
        Node *node = merged.head;
        while(node) {
            cout << node->elem << (node->next?' ':'\n');
            node = node->next;
        }
    }
    return 0;
}
