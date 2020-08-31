// You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.
// Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.

#include <iostream> 

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* last;
    Node* flatten(Node* head) {
        if (head == NULL) return NULL; 
        Node* ans = new Node; 
        ans->val = -1; 
        ans->prev = NULL;
        ans->next = NULL;
        ans->child = NULL;
        Node* p = head; 
        last = ans;
        preOrder(p);
        ans->next->prev = NULL;
        return ans->next; 
    }
    void preOrder(Node* p) {
        if (p == NULL) return; 
        add(p->val);
        preOrder(p->child);
        preOrder(p->next);
    }

    void add(int val) {
        last->next = new Node; 
        last->next->val = val; 
        last->next->prev = last; 
        last->next->next = NULL; 
        last->next->child = NULL;
        last = last->next;
    }
};