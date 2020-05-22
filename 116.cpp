// You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:
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
        if (!root->left) return; 
        root->left->next = root->right; 
        if (root->next) root->right->next = root->next->left;
        recur(root->left);
        recur(root->right);
    }
    Node* connect(Node* root) {
        recur(root);
        return root;
    }
};

// Solution
// 由于是完全二叉树，所以若节点的左子结点存在的话，其右子节点必定存在，所以左子结点的next指针可以直接指向其右子节点，对于其右子节点的处理方法是，判断其父节点的next是否为空，若不为空，则指向其next指针指向的节点的左子结点，若为空则指向NULL。