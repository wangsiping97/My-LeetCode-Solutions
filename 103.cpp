// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

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
    vector< vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector< vector<int> > ans;
        if (!root) return ans; 
        deque<TreeNode*> q; 
        int zigzag = 1;
        q.push_back(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> temp;
            for (int i = 0; i < sz; ++i) {
                temp.push_back(q.front()->val);
                if (q.front()->left) q.push_back(q.front()->left);
                if (q.front()->right) q.push_back(q.front()->right);
                q.pop_front();
            }
            if (zigzag == 0) reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            zigzag = 1 - zigzag;
        }
        return ans; 
    }
};