// Given a linked list, swap every two adjacent nodes and return its head.
// You may not modify the values in the list's nodes, only nodes itself may be changed.

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* i = NULL;
        ListNode* j = head;
        if (j == NULL) return head;
        ListNode* k = j->next;
        if (k == NULL) return head;
        j->next = k->next;
        k->next = j;
        head = k;
        while (j->next != NULL) {
            i = j;
            j = j->next;
            k = j->next;
            if (k == NULL) break;
            i->next = k;
            j->next = k->next;
            k->next = j;
        }
        return head;
    }
};