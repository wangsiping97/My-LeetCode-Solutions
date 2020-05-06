// Given a binary tree, return the inorder traversal of its nodes' values.

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
    vector<int> ans; 
    void inorder(TreeNode* tree) {
        if (tree == NULL) return;
        inorder(tree->left);
        ans.push_back(tree->val);
        inorder(tree->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
};