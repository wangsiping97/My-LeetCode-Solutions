// Given a non-empty, singly linked list with head node head, return a middle node of linked list.
// If there are two middle nodes, return the second middle node.

#include <iostream> 
using namespace std; 

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* pfast = head; 
        ListNode* p = head; 
        while (pfast) {
            pfast = pfast->next;
            if (!pfast) return p; 
            pfast = pfast->next;
            p = p->next; 
        }
        return p;
    }
};