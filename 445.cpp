// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Follow up:
// What if you cannot modify the input lists? In other words, reversing the lists is not allowed. 

#include <iostream> 
#include <stack> 
using namespace std; 

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2; 
        ListNode *p1 = l1, *p2 = l2;
        while (p1) {
            s1.push(p1->val);
            p1 = p1->next;
        }
        while (p2) {
            s2.push(p2->val);
            p2 = p2->next;
        }
        ListNode* ans = nullptr;
        int up = 0;
        while (!s1.empty() && !s2.empty()) {
            ans = new ListNode(0, ans);
            int value = s1.top() + s2.top() + up;
            s1.pop();
            s2.pop();
            if (value >= 10) {
                value -= 10;
                up = 1;
            }
            else up = 0;
            ans->val = value;
        }
        while (!s1.empty()) {
            ans = new ListNode(0, ans);
            int value = s1.top() + up;
            s1.pop();
            if (value >= 10) {
                value -= 10; 
                up = 1; 
            }
            else up = 0;
            ans->val = value;
        }
        while (!s2.empty()) {
            ans = new ListNode(0, ans);
            int value = s2.top() + up; 
            s2.pop();
            if (value >= 10) {
                value -= 10;
                up = 1;
            }
            else up = 0;
            ans->val = value;
        }
        if (up == 1) {
            ans = new ListNode(up, ans);
        }
        return ans; 
    }
};