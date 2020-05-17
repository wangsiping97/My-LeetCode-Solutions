// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

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
    vector< vector<int> > levelOrder(TreeNode* root) {
        vector< vector<int> > ans; 
        if (!root) return ans;
        deque<TreeNode*> q;
        q.push_back(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> temp;
            for (int i = 0; i < sz; ++i) {
                TreeNode* top = q.front();
                q.pop_front();
                if (top->left) q.push_back(top->left);
                if (top->right) q.push_back(top->right);
                temp.push_back(top->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};