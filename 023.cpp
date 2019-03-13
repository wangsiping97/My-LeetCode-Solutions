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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans;
        int l = lists.size();
        vector<int> v;
        if (l == 0) return NULL;
        for (int i = 0; i < l; i++) {
            ListNode*p = lists[i];
            while (p) {
                v.push_back(p->val);
                p = p->next;
            }
        }
        sort(v.begin(), v.end());
        int vl = v.size();
        if (vl == 0) return NULL;
        ans = new ListNode(v[0]);
        ListNode* p = ans;
        for (int i = 1; i < vl; i++) {
            p->next = new ListNode(v[i]);
            p = p->next;
        }
        return ans;
    }
};