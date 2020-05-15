// Sort a linked list in O(n log n) time using constant space complexity.

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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *pfast = head->next, *pslow = head;
        while (pfast != NULL && pfast->next != NULL) {
            pfast = pfast->next->next; 
            pslow = pslow->next;
        }
        ListNode* newHead = pslow->next;
        pslow->next = NULL;
        return merge(sortList(head), sortList(newHead));
    }
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode *p1 = list1, *p2 = list2;
        ListNode* head = new ListNode();
        ListNode* node = head;
        while (p1 && p2) {
            if (p1->val < p2->val) {
                node->next = p1;
                p1 = p1->next;
            }
            else {
                node->next = p2;
                p2 = p2->next;
            }
            node = node->next;
        }
        if (p1) node->next = p1;
        if (p2) node->next = p2;
        return head->next; 
    }
};