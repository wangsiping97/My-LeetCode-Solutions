// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

// Example:

// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4

#include <iostream> 
#include <list>
using namespace std; 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return NULL;
        else if (!l1) return l2;
        else if (!l2) return l1;
        else {
            ListNode* p;
            if (l1->val < l2->val) {
                p = l2;
                ListNode* p1 = l1->next;
                ListNode* q1 = l1;
                while (p) {
                    while (p1 && p1->val < p->val) {
                        p1 = p1->next;
                        q1 = q1->next;
                    }
                    q1->next = new ListNode(p->val);
                    q1 = q1->next;
                    q1->next = p1;
                    p = p->next;
                }
                return l1;
            }
            else {
                p = l1;
                ListNode* p2 = l2->next;
                ListNode* q2 = l2;
                while (p) {
                    while (p2 && p2->val < p->val) {
                        p2 = p2->next;
                        q2 = q2->next;
                    }
                    q2->next = new ListNode(p->val);
                    q2 = q2->next;
                    q2->next = p2;
                    p = p->next;
                }
                return l2;
            }
        }
    }
};