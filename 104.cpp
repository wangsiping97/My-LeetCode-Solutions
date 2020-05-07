// Given a binary tree, find its maximum depth.
// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
// Note: A leaf is a node with no children.

#include <iostream> 
#include <vector> 
#include <deque> 
#include <unordered_map> 
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
    int tempans; 
    int ans; 
    void dfs(TreeNode* t) {
        if (t == NULL) {
            ans = max(ans, tempans);
            tempans = 0;
            return;
        }
        tempans++;
        int temp = tempans;
        dfs(t->left);
        tempans = temp;
        dfs(t->right);
    }
    int maxDepth(TreeNode* root) {
        tempans = 0;
        ans = 0;
        dfs(root);
        return ans; 
    }
};