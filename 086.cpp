// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
// You should preserve the original relative order of the nodes in each of the two partitions.

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
    ListNode* partition(ListNode* head, int x) {
        ListNode *pre = new ListNode(INT_MIN); 
        pre->next = head; 
        ListNode *pfast = head, *pslow = pre; 
        while (pfast && pfast->val < x) {
            pfast = pfast->next; 
            pslow = pslow->next; 
        }
        ListNode* prepfast = pslow; 
        while (pfast) {
            if (pfast->val < x) {
                prepfast->next = pfast->next; 
                pfast->next = pslow->next; 
                pslow->next = pfast; 
                pslow = pfast;
                pfast = prepfast->next;
            }
            else {
                pfast = pfast->next; 
                prepfast = prepfast->next;
            }
        }
        return pre->next; 
    }
};