#include "List.h"

int main()
{
    List ds;

    ds.input();

    cout << "List ban dau: ";
    ds.print();

    cout << "\nTong: ";
    cout << ds.sum();

    cout << "\nMax: ";
    int m;
    if (ds.findMax(m)) cout << m;
    else cout << "List rong";

    ds.reverse();
    cout << "\nDao nguoc: ";
    ds.print();

    ds.insertFirst(100);
    cout << "\nThem dau: ";
    ds.print();

    ds.insertLast(200);
    cout << "\nThem cuoi: ";
    ds.print();

    ds.insertK(300, 2);
    cout << "\nThem vao vi tri k: ";
    ds.print();

    ds.deleteFirst();
    cout << "\nxoa dau: ";
    ds.print();

    ds.deleteLast();
    cout << "\nxoa cuoi: ";
    ds.print();

    ds.deleteK(2);
    cout << "\nxoa vi tri k: ";
    ds.print();

    ds.deleteX(2);
    cout << "\nxoa 2: ";
    ds.print();

    ds.deleteAllX1(2);
    cout << "\nxoa het 2: ";
    ds.print();

    return 0;
}
