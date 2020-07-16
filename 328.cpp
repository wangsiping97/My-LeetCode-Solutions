// Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
// You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

#include <iostream> 
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *pfast = head, *pslow = head; 
        while (pfast) {
            pfast = pfast->next;
            if (!pfast) break;
            ListNode* temp = pfast->next;
            if (!temp) break;
            // delete temp from the list
            pfast->next = temp->next;
            // put temp in the next position of pslow
            temp->next = pslow->next;
            pslow->next = temp;
            pslow = pslow->next; 
        }
        return head;
    }
};