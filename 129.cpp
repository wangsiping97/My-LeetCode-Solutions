// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
// An example is the root-to-leaf path 1->2->3 which represents the number 123.
// Find the total sum of all root-to-leaf numbers.
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
    int temp;
    int ans; 
    void dfs(TreeNode* node) {
        if (node == NULL) return; 
        if (node->left == NULL && node->right == NULL) {
            ans += temp;
            return; 
        }
        int num = temp;
        if (node->left != NULL) {
            temp = temp * 10 + node->left->val;
            dfs(node->left);
            temp = num;
        }
        if (node->right != NULL) {
            temp = temp * 10 + node->right->val;
            dfs(node->right);
            temp = num;
        }
    }
    int sumNumbers(TreeNode* root) {
        ans = 0;
        if (root == NULL) return ans; 
        temp = root->val;
        dfs(root);
    }
};