#pragma once
#include "List.h"
#include "LinkedList.h"

// ================= QUEUE (vao truoc ra truoc - FIFO) =================

// Queue dung List: dau hang la dau mang
struct QueueList
{
    List ds;

    bool empty() const
    {
        return ds.n == 0;
    }

    // them vao cuoi hang O(1), day thi khong lam gi
    void enqueue(int x)
    {
        ds.insertLast(x);
    }

    // lay dau hang ra O(n) vi phai dich mang, tra ve gia tri bi xoa, rong tra ve ERR
    int dequeue()
    {
        return ds.deleteFirst();
    }

    // xem dau hang (khong xoa), rong tra ve ERR
    int front() const
    {
        if (empty()) return ERR;
        return ds.a[0];
    }

    // in tu dau hang den cuoi hang
    void print() const
    {
        ds.print();
    }
};

// Queue dung LinkedList: dau hang la dau danh sach
struct QueueLinkedList
{
    LinkedList ds;

    bool empty() const
    {
        return ds.head == nullptr;
    }

    // them vao cuoi hang O(n) vi addLast phai duyet toi cuoi
    void enqueue(int x)
    {
        ds.addLast(x);
    }

    // lay dau hang ra O(1), tra ve gia tri bi xoa, rong tra ve ERR
    int dequeue()
    {
        return ds.deleteFirst();
    }

    // xem dau hang (khong xoa), rong tra ve ERR
    int front() const
    {
        if (empty()) return ERR;
        return ds.head -> data;
    }

    // in tu dau hang den cuoi hang
    void print() const
    {
        ds.print();
    }
};
