// Given a non-empty binary tree, find the maximum path sum.
// For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

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
    int m;
    int maxPathSum(TreeNode* root) {
        m = INT_MIN;
        path(root);
        return m;
    }
    int path(TreeNode* node) {
        if (node == NULL) return 0; 
        int left = max(path(node->left), 0);
        int right = max(path(node->right), 0);
        m = max(m, left + right + node->val);
        return max(left, right) + node->val;
    }
};