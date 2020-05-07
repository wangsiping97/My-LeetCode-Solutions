// Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

#include <iostream> 
#include <vector> 
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
    int ans;
    int getDepth(TreeNode* t) {
        if (t == NULL) return 0; 
        int left = getDepth(t->left);
        int right = getDepth(t->right);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0; 
        getDepth(root);
        return ans;
    }
};

// Solution
// 穿过任意一个节点的直径，为这个节点左子树的深度+右子树的深度
// So we need to compute the depth of each node in the tree!