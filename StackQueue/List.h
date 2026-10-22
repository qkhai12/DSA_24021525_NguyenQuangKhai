#pragma once
#include <iostream>
#include "common.h"

using namespace std;

const int MAX = 100;

struct List
{
    int a[MAX];
    int n;

    List() : n(0) {}

    // Nhap List
    void input()
    {
        cin >> n;
        if (n > MAX) n = MAX;
        if (n < 0) n = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    }

    // Duyet va in List
    void print() const
    {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
    }

    // tim x o vi tri nao O(n), khong thay tra ve -1
    int findX(int x) const
    {
        for (int i = 0; i < n; i++) {
            if (a[i] == x) {
                return i;
            }
        }

        return -1;
    }

    // Tinh tong
    int sum() const
    {
        int s = 0;

        for (int i = 0; i < n; i++) {
            s += a[i];
        }

        return s;
    }

    // Tim max, tra ve false neu List rong
    bool findMax(int &m) const
    {
        if (n == 0) return false;

        m = a[0];

        for (int i = 1; i < n; i++) {
            if (a[i] > m) {
                m = a[i];
            }
        }

        return true;
    }

    // Dao nguoc O(n)
    void reverse()
    {
        int left = 0;
        int right = n - 1;

        while (left < right) {
            swap(a[left], a[right]);
            left++;
            right--;
        }
    }

    // Chen vao vi tri k (k tinh tu 0) O(n)
    bool insertK(int x, int k)
    {
        if (n >= MAX || k < 0 || k > n) return false;

        for (int i = n; i > k; i--) {
            a[i] = a[i - 1];
        }

        a[k] = x;
        n++;
        return true;
    }

    // Chen dau O(n)
    bool insertFirst(int x)
    {
        return insertK(x, 0);
    }

    // Chen cuoi O(1)
    bool insertLast(int x)
    {
        if (n >= MAX) return false;

        a[n] = x;
        n++;
        return true;
    }

    // xoa o vi tri k (k tinh tu 0) O(n)
    // tra ve gia tri bi xoa, that bai tra ve ERR
    int deleteK(int k)
    {
        if (k < 0 || k >= n) return ERR;

        int removed = a[k];

        for (int i = k; i < n - 1; i++) {
            a[i] = a[i + 1];
        }

        n--;
        return removed;
    }

    // xoa dau O(n)
    int deleteFirst()
    {
        return deleteK(0);
    }

    // Xoa cuoi O(1)
    int deleteLast()
    {
        if (n == 0) return ERR;

        n--;
        return a[n];
    }

    // xoa phan tu dau tien co value = x O(n), tra ve x neu xoa duoc, khong thi ERR
    int deleteX(int x)
    {
        int k = findX(x);

        if (k == -1) return ERR;

        return deleteK(k);
    }

    // xoa all x O(n2) cach 1
    void deleteAllX1(int x)
    {
        while (findX(x) != -1) {
            deleteX(x);
        }
    }

    // xoa all x O(n2) cach 2
    void deleteAllX2(int x)
    {
        for (int i = 0; i < n; ) {
            if (a[i] == x) {
                deleteK(i);
            }
            else {
                i++;
            }
        }
    }
};
