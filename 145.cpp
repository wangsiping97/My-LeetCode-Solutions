// Given a binary tree, return the postorder traversal of its nodes' values.

#include <iostream> 
#include <vector> 
#include <stack> 
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans; 
        stack<TreeNode*> s; 
        s.push(root);
        while (!s.empty()) {
            TreeNode* top = s.top();
            s.pop();
            if (top == NULL) continue;
            if (top->left != NULL) s.push(top->left);
            if (top->right != NULL) s.push(top->right);
            ans.push_back(top->val);
        }
        reverse(ans.begin(), ans.end());
        return ans; 
    }
};