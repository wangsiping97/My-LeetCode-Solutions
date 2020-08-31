// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

// Example:

// Given this linked list: 1->2->3->4->5

// For k = 2, you should return: 2->1->4->3->5

// For k = 3, you should return: 3->2->1->4->5

// Note:

// Only constant extra memory is allowed.
// You may not alter the values in the list's nodes, only nodes itself may be changed.

#include <iostream>
using namespace std; 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int t;
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* p = head; 
        while (p) {
            count++; 
            p = p->next;
        }
        t = count / k;
        ListNode* hhead = new ListNode(-1);
        hhead->next = head;
        p = hhead; 

        while (t) {
            ListNode* last = reverse(p, k);
            t--;
            if (!last) break;
            p = last; 
        }
        
        return hhead->next;
    }
    ListNode* reverse(ListNode* p, int k) { // reverse the list from p->next with n = k
        if (t == 0) return NULL; 
        ListNode* last = p->next;
        ListNode* prev = p;
        ListNode* cur = p->next;
        ListNode* next = cur->next; 
        while (k) {
            cur->next = prev; 
            prev = cur; 
            cur = next; 
            if (next) next = next->next;
            k--;
        }
        p->next = prev;
        last->next = cur; 
        return last; 
    }
};