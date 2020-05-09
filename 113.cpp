// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
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
    vector< vector<int> > ans; 
    vector<int> temp; 
    void dfs(TreeNode* node, int sum) {
        if (node == NULL) return; 
        if (node->left == NULL && node->right == NULL) {
            if (sum == 0) ans.push_back(temp);
            return;
        }
        if (node->left != NULL) {
            temp.push_back(node->left->val);
            dfs(node->left, sum - node->left->val);
            temp.pop_back();
        }
        if (node->right != NULL) {
            temp.push_back(node->right->val);
            dfs(node->right, sum = node->right->val);
            temp.pop_back();
        }
    }
    vector< vector<int> > pathSum(TreeNode* root, int sum) {
        if (root == NULL) return ans;
        temp.push_back(root->val);
        dfs(root, sum - root->val);
        return ans; 
    }
};