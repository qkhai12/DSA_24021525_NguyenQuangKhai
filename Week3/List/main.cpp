#include <iostream>

using namespace std;

// Duyet va in List
void printList(int a[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

// tim x o vi tri nao O(n)
int findX(int a[], int n, int x)
{
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i;
        }
    }

    return -1;
}

// Tinh tong
int sumList(int a[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    return sum;
}

// Tim max
int findMax(int a[], int n)
{
    int m = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] > m) {
            m = a[i];
        }
    }

    return m;
}

// Dao nguoc O(n)
void reverseList(int a[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right) {
        swap(a[left], a[right]);
        left++;
        right--;
    }
}

// Chen dau O(n)
void insertFirst(int a[], int &n, int x)
{
    for (int i = n; i > 0; i--) {
        a[i] = a[i - 1];
    }

    a[0] = x;
    n++;
}

// Chen cuoi O(1)
void insertLast(int a[], int &n, int x)
{
    a[n] = x;
    n++;
}

// Chen vao vi tri k O(n)
void insertK(int a[], int &n, int x, int k)
{
    for (int i = n; i > k; i--) {
        a[i] = a[i - 1];
    }

    a[k] = x;
    n++;
}

// xoa dau O(n)
void deleteFirst(int a[], int &n)
{
    for (int i = 0; i < n-1; i++){
        a[i] = a[i+1];
    }
    n--;
}

// Xoa cuoi O(1)
void deleteLast(int a[], int &n)
{
    n--;
}
 // xoa o vi tri k O(n)
 void deleteK(int a[], int &n, int k)
 {
     for (int i = k - 1; i < n - 1; i++){
        a[i] = a[i+1];
     }
     n--;
 }

 // xoa o co value= x O(n)
 void deleteX(int a[], int &n, int x)
{
    int k = findX(a, n, x);

    if (k != -1) {
        for (int i = k; i < n - 1; i++) {
            a[i] = a[i + 1];
        }
        n--;
    }
}

// xoa all x O(n2) cach 1
void deleteAllX1(int a[], int &n, int x)
{
    while (findX(a, n, x) != -1) {
        deleteX(a, n, x);
    }
}

// xoa all x O(n2) cach 2
void deleteAllX2(int a[], int &n, int x)
{
    for (int i = 0; i < n; ) {
        if (a[i] == x) {
            for (int j = i; j < n - 1; j++) {
                a[j] = a[j + 1];
            }
            n--;
        }
        else {
            i++;
        }
    }
}



int main()
{
    int a[100];
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "List ban dau: ";
    printList(a, n);

    cout << "\nTong: ";
    cout << sumList(a, n);

    cout << "\nMax: ";
    cout << findMax(a, n);

    reverseList(a, n);
    cout << "\nDao nguoc: ";
    printList(a, n);

    insertFirst(a, n, 100);
    cout << "\nThem dau: ";
    printList(a, n);

    insertLast(a, n, 200);
    cout << "\nThem cuoi: ";
    printList(a, n);

    insertK(a, n, 300, 2);
    cout << "\nThem vao vi tri k: ";
    printList(a, n);

    deleteFirst(a,n);
    cout << "\nxoa dau: ";
    printList(a, n);

    deleteLast(a,n);
    cout << "\nxoa cuoi: ";
    printList(a, n);

    deleteK(a,n,2);
    cout << "\nxoa vi tri k: ";
    printList(a, n);

    deleteX(a,n,2);
    cout << "\nxoa 2: ";
    printList(a, n);

    deleteAllX1(a,n,2);
    cout << "\nxoa het 2: ";
    printList(a, n);

    return 0;
}
