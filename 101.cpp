// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

#include <iostream> 
#include <vector> 
#include <deque> 
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
    bool dfs(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        else if (!left || !right) return false;
        if (left->val != right->val) return false; 
        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true; 
        return dfs(root->left, root->right);
    }
};