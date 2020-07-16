// Reverse a singly linked list.

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
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head; 
        ListNode* ans = nullptr; 
        while (p) {
            ans = new ListNode(p->val, ans);
            p = p->next;
        }
        return ans; 
    }
};