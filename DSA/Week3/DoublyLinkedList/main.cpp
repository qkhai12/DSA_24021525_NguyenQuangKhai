#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* createNode(int x)
{
    Node* p = new Node;
    p -> data = x;
    p -> next = nullptr;
    p -> prev = nullptr;
    return p;
}
// O(1)
void addFirst( Node*& head, int x)
{
    Node* p = createNode(x);
    if (head == nullptr){
        head = p;
        return;
    }
    p-> next = head;
    head -> prev = p;
    head = p;
}

// O(n)
void printForward(Node* head)
{
    Node* p = head;
    while(p != nullptr){
        cout << p -> data <<" ";
        p = p -> next;
    }
    cout << endl;
}

// O(n)
void addLast(Node* &head, int x)
{
    if(head == nullptr){
        addFirst(head,x);
        return;
    }
    Node* p = head;
    while(p -> next != nullptr){
        p = p -> next;
    }
    Node* q = createNode(x);
    q -> prev = p;
    p -> next = q;
}

// O(n)
void addK(Node*& head, int k, int x)

{
    if (k == 0) {
        addFirst(head, x);
        return;
    }
    Node* p = head;
    for (int i = 0; i < k-1 && p != nullptr;i++){
        p = p -> next;
    }
    if (p == nullptr){
        return;
    }
     Node* q = createNode(x);

    q->prev = p;
    q->next = p->next;

    if (p->next != nullptr) {
        p->next->prev = q;
    }

    p->next = q;
}


 // O(n)
void printBackward(Node* head)
{
    if (head == nullptr) {
        return;
    }
    Node* p = head;
    while(p -> next != nullptr){
        p = p -> next;
    }
    while (p!= nullptr){
        cout << p -> data <<" ";
        p = p -> prev;
    }
    cout << endl;
}

// O(1)
void deleteFirst(Node*& head)
{
    if (head == nullptr) {
        return;
    }

    Node* p = head;

    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }

    delete p;
}

// O(n)
void deleteLast(Node* & head)
{
    if( head == nullptr){
        return;
    }
    if (head -> next == nullptr){
        deleteFirst(head);
        return;
    }
    //c1
    Node* p = head;
    while(p -> next -> next != nullptr){
        p = p -> next;
    }
    delete p -> next;
    p -> next = nullptr;

/*c2
    Node* p = head;
    while (p->next != nullptr) {
    p = p->next;
}

p->prev->next = nullptr;
delete p;
*/


}

//O(n)
void deleteK(Node* &head, int k)
{
    if (head == nullptr) {
    return;
}

    if(k == 0){
        deleteFirst(head);
        return;
    }
    Node* p = head;
    for (int i=0; i< k&& p!= nullptr;i++ ){
        p = p-> next;
    }
    if (p == nullptr){
        return;
    }
    if (p->next == nullptr) {
    deleteLast(head);
    return;
}
    p -> next -> prev = p-> prev;
    p -> prev -> next = p -> next;
    delete p;
}

int main()
{
    Node* head = nullptr;

    // =========================
    // 1. Test addFirst
    // =========================
    cout << "1. addFirst:" << endl;

    addFirst(head, 30);
    addFirst(head, 20);
    addFirst(head, 10);

    cout << "Forward: ";
    printForward(head);

    cout << "Backward: ";
    printBackward(head);
    cout << endl;


    // =========================
    // 2. Test addLast
    // =========================
    cout << "2. addLast:" << endl;

    addLast(head, 40);
    addLast(head, 50);

    cout << "Forward: ";
    printForward(head);

    cout << "Backward: ";
    printBackward(head);
    cout << endl;


    // =========================
    // 3. Test addK
    // =========================
    cout << "3. addK:" << endl;

    // Them vao dau
    addK(head, 0, 5);

    // Them vao giua
    addK(head, 3, 25);

    // Them vao cuoi
    addK(head, 7, 60);

    cout << "Forward: ";
    printForward(head);

    cout << "Backward: ";
    printBackward(head);
    cout << endl;


    // =========================
    // 4. Test deleteFirst
    // =========================
    cout << "4. deleteFirst:" << endl;

    deleteFirst(head);

    cout << "Forward: ";
    printForward(head);

    cout << "Backward: ";
    printBackward(head);
    cout << endl;


    // =========================
    // 5. Test deleteLast
    // =========================
    cout << "5. deleteLast:" << endl;

    deleteLast(head);

    cout << "Forward: ";
    printForward(head);

    cout << "Backward: ";
    printBackward(head);
    cout << endl;


    // =========================
    // 6. Test deleteK
    // =========================
    cout << "6. deleteK:" << endl;

    // Xoa dau
    deleteK(head, 0);

    cout << "Sau khi xoa index 0: ";
    printForward(head);

    // Xoa giua
    deleteK(head, 2);

    cout << "Sau khi xoa index 2: ";
    printForward(head);

    // Xoa cuoi
    deleteK(head, 3);

    cout << "Sau khi xoa index 3: ";
    printForward(head);

    cout << "Backward: ";
    printBackward(head);
    cout << endl;


    // =========================
    // 7. Xoa het danh sach
    // =========================
    while (head != nullptr) {
        deleteFirst(head);
    }

    cout << "Sau khi xoa het: ";
    printForward(head);


    return 0;
}
