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
        {
            tail = tail->next = new Node(elem);
        }
    }
    void reverse() {
        Node *a, *b, *c;
        
        if(head == NULL || head->next == NULL)
            return;
        if(head->next->next == NULL){
            swap(head->elem, head->next->elem);
        }

        a = head, b = head->next ,c = head->next->next;
        head->next = NULL;
        tail = head; //update
        while(c != NULL){
            b->next = a;
            a = b;
            b = c;
            c = c->next;
        }
        b->next = a;
        head = b; //update
    }
    Node *head, *tail;
};
int main() {
    int M;
    cin >> M;
    while(M--) {
        int N;
        cin>>N;
        //读取输入
        List list;
        for(int i=0;i<N;i++) {
            int temp;
            cin>>temp;
            list.append(temp);
        }
        //倒置链表
        list.reverse();
        //输出结果
        Node *node = list.head;
        while(node) {
            cout << node->elem << (node->next?' ':'\n');
            node = node->next;
        }
    }
    return 0;
}
