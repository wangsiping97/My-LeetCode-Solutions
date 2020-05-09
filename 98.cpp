// Given a binary tree, determine if it is a valid binary search tree (BST).

// Assume a BST is defined as follows:
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

#include <iostream> 
#include <vector> 
using namespace std; 

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int* temp = NULL;
    bool isValidBST(TreeNode* root) {
        if (root ==NULL) return true; 
        if (!isValidBST(root->left)) return false; 
        if (temp != NULL && *temp >= root->val) return false;
        *temp = root->val;
        if (!isValidBST(root->right)) return false; 
        return true; 
    }
};