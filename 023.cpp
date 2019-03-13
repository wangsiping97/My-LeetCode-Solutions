// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

// Example:
// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6

#include <iostream>
#include <vector> 
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode (int x):val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* merge2Lists(ListNode* a, ListNode* b) {
        ListNode* pa = a;
        ListNode* pb = b;
        ListNode *ans;
        if (!a && !b) return NULL;
        else if (!a) return b;
        else if (!b) return a;
        if (pa->val <= pb->val) {
            ans = new ListNode(pa->val);
            pa = pa->next;
        }
        else {
            ans = new ListNode(pb->val);
            pb = pb->next;
        }
        ListNode *p = ans;
        while (pa && pb) {
            if (pa->val <= pb->val) {
                p->next = new ListNode(pa->val);
                p = p->next;
                pa = pa->next;
            }
            else {
                p->next = new ListNode(pb->val);
                p = p->next;
                pb = pb->next;
            }
        }
        while (pa) {
            p->next = new ListNode(pa->val);
            p = p->next;
            pa = pa->next;
        }
        while (pb) {
            p->next = new ListNode(pb->val);
            p = p->next;
            pb = pb->next;
        }
        free(a);
        free(b);
        return ans;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int l = lists.size();
        if (l == 0) return NULL;
        ListNode* ans = lists.back();
        lists.pop_back();
        while (!lists.empty()) {
            ans = merge2Lists(ans, lists.back());
            lists.pop_back();
        }
        return ans;
    }
};