#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

// tao node
Node* createNode(int x)
{
    Node* p = new Node;
    p -> data = x;
    p -> next = nullptr;
    return p;
}

// in LinkedList
void printLinkedList(Node* head)
{
    Node* p = head;
    while(p != nullptr){
        cout << p -> data<<" ";
        p = p -> next;
    }
}

// them vao cuoi
void addLast(Node* &head, int x)
{
    Node* p = createNode(x);
    if (head == nullptr){
        head = p;
        return;
    }

    Node* tmp = head;
    while (tmp -> next != nullptr){
        tmp = tmp -> next;
    }
    tmp -> next = p;
}
// them dau
void addFirst( Node* &head, int x)
{
    Node* p = createNode(x);
    if (head == nullptr){
        head = p;
        return;
    }
    p -> next = head;
    head = p;

}

// them giua dung while
void addK1(Node* &head, int k, int x)
{
    if (k == 0){
        addFirst(head, x);
        return;
    }
    Node* tmp = head;
    Node* p = createNode(x);
    while(k != 1 && tmp -> next != nullptr){
        tmp = tmp -> next;
        k--;
    }
    p -> next = tmp -> next;
    tmp -> next = p;
}
// them giua dung vong for
void addK2(Node*& head, int k, int x)
{
    if (k == 0) {
        addFirst(head, x);
        return;
    }

    Node* tmp = head;

    for (int i = 0; i < k - 1 && tmp != nullptr; i++) {
        tmp = tmp -> next;
    }

    if (tmp == nullptr)
        return;

    Node* p = createNode(x);

    p -> next = tmp -> next;
    tmp -> next = p;
}

// in nguoc
void printReverse(Node* head)
{
    Node* p = head;
    if(p == nullptr){
        return;
    }
    printReverse(p -> next);
    cout << p -> data << " ";

}

// xoa dau
void deleteFirst(Node* &head)
{
    if (head == nullptr){
        return;
    }
    Node* p = head;
    head = head -> next;
    delete p;
}

// xoa cuoi
void deleteLast(Node* &head)
{
    if(head == nullptr){
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* p = head;
    while(p -> next -> next != nullptr){
        p = p -> next;
    }
    delete p -> next;
    p -> next = nullptr;

}

// xoa o K
void deleteK(Node* &head, int k)
{
    if (k == 0){
        deleteFirst(head);
        return;
    }

    Node* p = head;
     for (int i = 0; i < k - 1 && p != nullptr; i++){
        p = p-> next;
     }
     if (p == nullptr || p->next == nullptr){
        return;
     }
     Node* q = p -> next;
     p -> next = p -> next -> next;
     delete q;
}



int main() {
    Node* head = nullptr;

    addLast(head, 10);
    addLast(head, 20);
    addLast(head, 30);
    addLast(head, 40);
    addFirst(head, 0);
    addK1(head, 3, 25);
    addK2(head, 3, 25);

    printLinkedList(head);
    cout<<endl;
    printReverse(head);
    cout<<endl;
    deleteFirst(head);
    printLinkedList(head);
    cout<<endl;
    deleteLast(head);
    printLinkedList(head);
    cout<<endl;
    deleteK(head,2);
    printLinkedList(head);
    cout<<endl;
    deleteK(head,2);
    printLinkedList(head);
    cout<<endl;



    return 0;
}
