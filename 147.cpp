// Sort a linked list using insertion sort.

#include <iostream> 
using namespace std; 

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* p = head->next; 
        ListNode* parent = head;
        while (p) {
            if (head->val > p->val) {
                parent->next = p->next;
                p->next = head;
                head = p;
                p = parent->next; 
                continue;
            }
            ListNode* q = head; 
            while (q != p && q->next->val <= p->val) q = q->next;
            if (q == p) {
                parent = p;
                p = p->next;
                continue;
            }
            parent->next = p->next;
            p->next = q->next;
            q->next = p;
            p = parent->next;
        }
        return head;
    }
};