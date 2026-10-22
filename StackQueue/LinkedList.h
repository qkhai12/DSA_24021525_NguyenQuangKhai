#pragma once
#include <iostream>
#include "common.h"

using namespace std;

struct Node
{
    int data;
    Node* next;
};

// tao node (inline vi ham nam ngoai struct trong file .h)
inline Node* createNode(int x)
{
    Node* p = new Node;
    p -> data = x;
    p -> next = nullptr;
    return p;
}

struct LinkedList
{
    Node* head;

    LinkedList() : head(nullptr) {}

    // khong cho copy de tranh giai phong bo nho 2 lan
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    // huy: giai phong toan bo node
    ~LinkedList()
    {
        clear();
    }

    // giai phong toan bo danh sach
    void clear()
    {
        while (head != nullptr) {
            deleteFirst();
        }
    }

    // in LinkedList
    void print() const
    {
        Node* p = head;
        while (p != nullptr) {
            cout << p -> data << " ";
            p = p -> next;
        }
    }

    // in nguoc (de quy)
    void printReverse() const
    {
        printReverse(head);
    }

    // them dau
    void addFirst(int x)
    {
        Node* p = createNode(x);
        p -> next = head;
        head = p;
    }

    // them cuoi
    void addLast(int x)
    {
        Node* p = createNode(x);

        if (head == nullptr) {
            head = p;
            return;
        }

        Node* tmp = head;
        while (tmp -> next != nullptr) {
            tmp = tmp -> next;
        }
        tmp -> next = p;
    }

    // them giua dung while (k tinh tu 0), tra ve false neu k khong hop le
    bool addK1(int k, int x)
    {
        if (k < 0) return false;

        if (k == 0) {
            addFirst(x);
            return true;
        }

        Node* tmp = head;
        int i = 0;
        while (tmp != nullptr && i < k - 1) {
            tmp = tmp -> next;
            i++;
        }

        if (tmp == nullptr) return false;

        Node* p = createNode(x);
        p -> next = tmp -> next;
        tmp -> next = p;
        return true;
    }

    // them giua dung vong for (k tinh tu 0), tra ve false neu k khong hop le
    bool addK2(int k, int x)
    {
        if (k < 0) return false;

        if (k == 0) {
            addFirst(x);
            return true;
        }

        Node* tmp = head;

        for (int i = 0; i < k - 1 && tmp != nullptr; i++) {
            tmp = tmp -> next;
        }

        if (tmp == nullptr) return false;

        Node* p = createNode(x);
        p -> next = tmp -> next;
        tmp -> next = p;
        return true;
    }

    // xoa dau, tra ve gia tri bi xoa, that bai tra ve ERR
    int deleteFirst()
    {
        if (head == nullptr) return ERR;

        Node* p = head;
        int removed = p -> data;
        head = head -> next;
        delete p;
        return removed;
    }

    // xoa cuoi
    int deleteLast()
    {
        if (head == nullptr) return ERR;

        if (head -> next == nullptr) {
            int removed = head -> data;
            delete head;
            head = nullptr;
            return removed;
        }

        Node* p = head;
        while (p -> next -> next != nullptr) {
            p = p -> next;
        }

        int removed = p -> next -> data;
        delete p -> next;
        p -> next = nullptr;
        return removed;
    }

    // xoa o K (k tinh tu 0), k khong hop le thi tra ve ERR
    int deleteK(int k)
    {
        if (k < 0 || head == nullptr) return ERR;

        if (k == 0) {
            return deleteFirst();
        }

        Node* p = head;
        for (int i = 0; i < k - 1 && p != nullptr; i++) {
            p = p -> next;
        }

        if (p == nullptr || p -> next == nullptr) return ERR;

        Node* q = p -> next;
        int removed = q -> data;
        p -> next = q -> next;
        delete q;
        return removed;
    }

private:
    static void printReverse(Node* p)
    {
        if (p == nullptr) return;

        printReverse(p -> next);
        cout << p -> data << " ";
    }
};
