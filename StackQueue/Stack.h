#pragma once
#include "List.h"
#include "LinkedList.h"

// ================= STACK (vao sau ra truoc - LIFO) =================

// Stack dung List: dinh stack la cuoi mang
struct StackList
{
    List ds;

    bool empty() const
    {
        return ds.n == 0;
    }

    // them vao dinh O(1), day thi khong lam gi
    void push(int x)
    {
        ds.insertLast(x);
    }

    // lay dinh ra O(1), tra ve gia tri bi xoa, rong tra ve ERR
    int pop()
    {
        return ds.deleteLast();
    }

    // xem dinh (khong xoa), rong tra ve ERR
    int top() const
    {
        if (empty()) return ERR;
        return ds.a[ds.n - 1];
    }

    // in tu day len dinh
    void print() const
    {
        ds.print();
    }
};

// Stack dung LinkedList: dinh stack la dau danh sach
struct StackLinkedList
{
    LinkedList ds;

    bool empty() const
    {
        return ds.head == nullptr;
    }

    // them vao dinh O(1)
    void push(int x)
    {
        ds.addFirst(x);
    }

    // lay dinh ra O(1), tra ve gia tri bi xoa, rong tra ve ERR
    int pop()
    {
        return ds.deleteFirst();
    }

    // xem dinh (khong xoa), rong tra ve ERR
    int top() const
    {
        if (empty()) return ERR;
        return ds.head -> data;
    }

    // in tu dinh xuong day
    void print() const
    {
        ds.print();
    }
};
