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
    int longest(TreeNode* root) {
        if (!root) return 0; 
        int ans = 0;
        dfs_preorder(root, root->val, 0, ans);
        return ans;
    }

    void dfs_preorder(TreeNode* root, int parent, int temp, int& ans) {
        if (!root) return; 
        if (root->val == parent + 1) temp++;
        else temp = 1;
        if (temp > ans) ans = temp;
        dfs_preorder(root->left, root->val, temp, ans);
        dfs_preorder(root->right, root->val, temp, ans);
    }
};

// Solution
// preorder dfs