// Given a binary tree, return all root-to-leaf paths.
// Note: A leaf is a node with no children.

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
    vector<string> ans; 
    void dfs(TreeNode* node, string temp) {
        if (node == NULL) return;
        if (node->left == NULL && node->right == NULL) {
            ans.push_back(temp);
            return; 
        }
        if (node->left != NULL) {
            dfs(node->left, temp + "->" + to_string(node->left->val));
        }
        if (node->right != NULL) {
            dfs(node->right, temp + "->" + to_string(node->right->val));
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) return ans; 
        string temp = to_string(root->val);
        dfs(root, temp);
        return ans; 
    }
};