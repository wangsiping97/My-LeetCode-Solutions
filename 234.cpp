// Given a singly linked list, determine if it is a palindrome.

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
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        ListNode *pfast = head, *pslow = head; 
        while (pfast) {
            pfast = pfast->next; 
            if (!pfast) break; 
            pfast = pfast->next;
            pslow = pslow->next; 
        }
        ListNode* cur = pslow->next; 
        pslow->next = nullptr; 
        if (!cur) return head->val == pslow->val;
        ListNode* lat = cur->next; 
        while (cur) {
            cur->next = pslow; 
            pslow = cur; 
            cur = lat;
            if (!cur) break;
            lat = lat->next; 
        }
        while (head && pslow) {
            if (head->val != pslow->val) return false; 
            head = head->next; 
            pslow = pslow->next;
        }
        return true; 
    }
};