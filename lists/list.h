#ifndef LIST_H
#define LIST_H

#include <iostream>
using std::cout;
using std::endl;

/**************************/
/*** Singly Linked List ***/
/**************************/
class SLinkedList {
    private:
    struct Node {
        int val;
        Node *next;
        Node(int val) : val(val), next(NULL) {}
    };
    Node *head;
    Node *tail; 

    public:
    SLinkedList();
    ~SLinkedList();
    void insertFront(int val);  
    void insertBack(int val);
    void insertAfter(int val, int x);
    void deleteFront();       
    void deleteBack();
    void deleteNode(int x);
    void print();
    bool empty();
    int size();

    void copyArray(int array[], int size);  
    void copyArrayRecur(int array[], int size, Node *node);
    void reverse();
    void reverseRecur1Helper(Node *node);
    void reverseRecur1();
    void reverseRecur2();
};

/**************************/
/*** Doubly Linked List ***/
/**************************/
class DLinkedList {
    private:
    struct Node {
        int val;
        Node *next;
        Node *prev;
        Node(int val) : val(val), next(NULL), prev(NULL) {}
    };
    Node *head;
    Node *tail;

    public:
    DLinkedList();
    ~DLinkedList();
    void insertFront(int val);  
    void deleteBack();
    void printForward();
    void printBackward();
    bool empty();
    int size();

    void swap(int x, int y);    
};

#endif
