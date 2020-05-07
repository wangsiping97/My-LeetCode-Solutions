// Given a binary tree, return the preorder traversal of its nodes' values.

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
    void preorder(TreeNode* t) {
        if (t == NULL) return; 
        ans.push_back(t->val);
        preorder(t->left);
        preorder(t->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return ans; 
    }
};