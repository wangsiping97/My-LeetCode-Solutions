// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example:

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807

#include <iostream> 
using namespace std; 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *ans = NULL;
        ListNode *p = ans;
        int up = 0;
        while (p1 && p2) {
            int sum = p1->val + p2->val + up;
            if (sum >= 10) {
                sum -= 10;
                up = 1;
            }
            else up = 0;
            if (!ans) 
                p = ans = new ListNode(sum);
            else {
                p->next = new ListNode(sum);
                p = p->next;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p1) {
            int sum = p1->val + up;
            if (sum >= 10) {
                sum -= 10;
                up = 1;
            }
            else up = 0;
            p->next = new ListNode(sum);
            p = p->next;
            p1 = p1->next;
        }
        while (p2) {
            int sum = p2->val + up;
            if (sum >= 10) {
                sum -= 10;
                up = 1;
            }
            else up = 0;
            p->next = new ListNode(sum);
            p = p->next;
            p2 = p2->next;
        }
        if (up == 1)
            p->next = new ListNode(1);
        return ans;
    }
};

void printList(ListNode *l) {
    ListNode *p = l;
    while (p) {
        cout << " -> " << p->val;
        p = p->next;
    }
    cout << endl;
}

int main() {
    ListNode *l1;
    l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode *l2;
    l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(9);
    printList(l1);
    printList(l2);

    Solution s;
    ListNode *ans = s.addTwoNumbers(l1, l2);
    printList(ans);

    return 0;
}