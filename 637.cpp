// Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans; 
        if (!root) return ans; 
        deque<TreeNode*> q;
        q.push_back(root);
        while (!q.empty()) {
            int sz = q.size();
            double sum = 0;
            for (int i = 0; i < sz; ++i) {
                TreeNode* top = q.front();
                q.pop_front();
                sum += top->val;
                if (top->left) q.push_back(top->left);
                if (top->right) q.push_back(top->right);
            }
            double ave = sum / sz;
            ans.push_back(ave);
        }
        return ans;
    }
};