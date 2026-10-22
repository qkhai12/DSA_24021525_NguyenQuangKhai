#include "Stack.h"
#include "Queue.h"

int main()
{
    // ---------- Stack dung List ----------
    StackList s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);

    cout << "StackList (day -> dinh): ";
    s1.print();
    cout << "\nTop: " << s1.top();
    cout << "\nPop: " << s1.pop();
    cout << "\nSau pop: ";
    s1.print();

    // ---------- Stack dung LinkedList ----------
    StackLinkedList s2;
    s2.push(1);
    s2.push(2);
    s2.push(3);

    cout << "\n\nStackLinkedList (dinh -> day): ";
    s2.print();
    cout << "\nTop: " << s2.top();
    cout << "\nPop: " << s2.pop();
    cout << "\nSau pop: ";
    s2.print();

    // ---------- Queue dung List ----------
    QueueList q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);

    cout << "\n\nQueueList (dau -> cuoi): ";
    q1.print();
    cout << "\nFront: " << q1.front();
    cout << "\nDequeue: " << q1.dequeue();
    cout << "\nSau dequeue: ";
    q1.print();

    // ---------- Queue dung LinkedList ----------
    QueueLinkedList q2;
    q2.enqueue(1);
    q2.enqueue(2);
    q2.enqueue(3);

    cout << "\n\nQueueLinkedList (dau -> cuoi): ";
    q2.print();
    cout << "\nFront: " << q2.front();
    cout << "\nDequeue: " << q2.dequeue();
    cout << "\nSau dequeue: ";
    q2.print();

    // ---------- Kiem tra khi rong ----------
    StackList rong;
    int v = rong.pop();
    if (v == ERR) cout << "\n\nStack rong, khong pop duoc";

    return 0;
}
