// You are given a binary tree. The binary tree has the following definition:
// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
// Initially, all next pointers are set to NULL.

// Follow up:
// You may only use constant extra space.
// Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.

#include<iostream> 
using namespace std; 

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    void recur(Node* root) {
        if (!root) return; 
        Node* p = root->next;
        while (p && !p->left && !p->right) p = p->next;
        if (root->right) {
            if (p && p->left) root->right->next = p->left;
            else if (p && p->right) root->right->next = p->right;
            if (root->left) root->left->next = root->right;
        }
        else if (root->left) {
            if (p && p->left) root->left->next = p->left;
            else if (p && p->right) root->left->next = p->right;
        }
        recur(root->right); // 注意顺序先right后left
        recur(root->left);
    }
    Node* connect(Node* root) {
        recur(root);
        return root;
    }
};