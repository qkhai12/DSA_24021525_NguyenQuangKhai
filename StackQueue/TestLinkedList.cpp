#include "LinkedList.h"

int main()
{
    LinkedList ds;

    ds.addLast(10);
    ds.addLast(20);
    ds.addLast(30);
    ds.addLast(40);
    ds.addFirst(0);
    ds.addK1(3, 25);
    ds.addK2(3, 25);

    ds.print();
    cout << endl;
    ds.printReverse();
    cout << endl;
    ds.deleteFirst();
    ds.print();
    cout << endl;
    ds.deleteLast();
    ds.print();
    cout << endl;
    ds.deleteK(2);
    ds.print();
    cout << endl;
    ds.deleteK(2);
    ds.print();
    cout << endl;

    return 0;
}
