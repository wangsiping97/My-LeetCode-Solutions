// Given a linked list, remove the n-th node from the end of list and return its head.
// Example:
// Given linked list: 1->2->3->4->5, and n = 2.
// After removing the second node from the end, the linked list becomes 1->2->3->5.

#include <cstdio>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> v;
        ListNode* iter = head;
        while (iter != NULL) {
            v.push_back(iter);
            iter = iter->next;
        }
        int target = v.size() - n;
        if (target == 0) {
            return head->next;
        }
        else {
            v[target - 1]->next = v[target + 1];
        }
        return head;
    }
};