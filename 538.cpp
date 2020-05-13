// Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

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
    int tempsum;
    void dfs(TreeNode* root) {
        if (root == NULL) return; 
        dfs(root->right);
        tempsum += root->val; 
        root->val += tempsum - root->val;
        dfs(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        tempsum = 0;
        dfs(root);
        return root;
    }
};