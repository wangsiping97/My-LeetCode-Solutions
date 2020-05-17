#include <iostream> 
#include <vector> 
using namespace std; 

/**
 * Definition for a binary tree node.
 */
class TreeNode {
public:
 int value;
 TreeNode* left;
 TreeNode* right;
 TreeNode(int v) : value(v), left(NULL), right(NULL) {}
};

class Solution {
public: 
    int longest(TreeNode* root) {
        if (!root) return 0; 
        int ans = 0;
        dfs_preorder(root, root->value, 0, ans);
        return ans;
    }

    void dfs_preorder(TreeNode* root, int parent, int temp, int& ans) {
        if (!root) return; 
        if (root->value > parent) temp++;
        else temp = 1;
        if (temp > ans) ans = temp;
        dfs_preorder(root->left, root->value, temp, ans);
        dfs_preorder(root->right, root->value, temp, ans);
    }
};