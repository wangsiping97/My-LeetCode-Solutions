// Reverse a linked list from position m to n. Do it in one-pass.

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *pre = head, *pivot, *lat; 
        ListNode *prepre = nullptr;
        for (int i = 1; i < m; ++i) {
            prepre = pre;
            pre = pre->next;
        }
        ListNode *pm = pre;

        pivot = pre->next;
        if (!pivot) return head; 
        lat = pivot->next; 

        for (int i = m; i < n; ++i) {
            pivot->next = pre; 
            pre = pivot;
            pivot = lat; 
            if (lat) lat = lat->next;
        }

        pm->next = pivot; 
        if (m == 1) return pre;
        else {
            prepre->next = pre;
            return head;
        }
    }
};