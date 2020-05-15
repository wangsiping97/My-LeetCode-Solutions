// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

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
    vector< vector<int> > levelOrderBottom(TreeNode* root) {
        vector< vector<int> > ans;
        if (!root) return ans; 
        deque<TreeNode*> q;
        q.push_back(root);
        vector<int> temp;
        while (!q.empty()) {
            int sz = q.size(); // very important step to improve speed!
            for (int i = 0; i < sz; ++i) {
                TreeNode* top = q.front();
                q.pop_front(); 
                temp.push_back(top->val); 
                if (top->left) q.push_back(top->left);
                if (top->right) q.push_back(top->right);
            }
            ans.push_back(temp);
            temp.clear();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};