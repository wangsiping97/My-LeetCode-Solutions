#include <iostream>
#include <vector> 
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *p = head;
        int l = 0;
        while (p) {
            l++;
            p = p->next;
        }
        if (l == 0 || k % l == 0) return head;
        k = l - k % l;
        int i = 0;
        p = head;
        while (i < k - 1) {
            p = p->next;
            i++;
        }
        ListNode* res = p->next;
        p->next = NULL;
        p = res;
        while (p->next) {
            p = p->next;
        }
        p->next = head;
        return res;
    }
};