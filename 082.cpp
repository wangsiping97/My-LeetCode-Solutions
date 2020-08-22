// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
// Return the linked list sorted as well.

#include <iostream> 
using namespace std; 

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head; 
        ListNode* p = head; 
        ListNode* hhead = new ListNode(-1, head);
        ListNode* pre = hhead; 
        int count; 
        while (p != NULL) {
            count = 1;
            for (; p->next != NULL; p = p->next) {
                if (p->next->val != p->val) break; 
                count++;
            }
            cout << count << endl; 
            if (count >= 2) {
                pre->next = p->next; 
            }
            p = p->next; 
        }
        return hhead->next; 
    }
};