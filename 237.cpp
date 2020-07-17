// Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
// Given linked list -- head = [4,5,1,9]

#include <iostream> 
using namespace std; 

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* pnext = node->next; 
        node->val = pnext->val; 
        node->next = pnext->next; 
        pnext->next = NULL; 
    }
};

// Solution
// 先把当前节点的值用下一个节点的值覆盖了，然后我们删除下一个节点即可。