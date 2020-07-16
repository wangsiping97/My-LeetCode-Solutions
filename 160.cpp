// Write a program to find the node at which the intersection of two singly linked lists begins.

#include <iostream> 
#include <stack> 
using namespace std; 

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        stack<ListNode*> s1, s2; 
        ListNode *pa = headA, *pb = headB; 
        while (pa) {
            s1.push(pa);
            pa = pa->next;
        }
        while (pb) {
            s1.push(pb);
            pb = pb->next;
        }
        pa = headA, pb = headB;
        while (pb) {
            s2.push(pb);
            pb = pb->next;
        }
        while (pa) {
            s2.push(pa);
            pa = pa->next; 
        }
        ListNode* ans = NULL;
        while (!s1.empty() && !s2.empty()) {
            if (s1.top() != s2.top()) break;
            else {
                ans = s1.top();
                s1.pop();
                s2.pop();
            }
        }
        return ans; 
    }
};