// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

#include <iostream> 
#include <vector> 
#include <unordered_map> 
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
    TreeNode* ans;
    int find(TreeNode* subtree, TreeNode* p, TreeNode* q) {
        if (subtree == NULL) return 0; 
        bool mid;
        if (subtree == p || subtree == q) mid = 1; 
        else mid = 0;
        int left = find(subtree->left, p, q);
        int right = find(subtree->right, p, q);
        if (mid + left + right >= 2) ans = subtree;
        return mid + left + right > 0 ? 1 : 0;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = NULL; 
        find(root, p, q);
        return ans;
    }
};

// Solution
// Recursive: for each TreeNode, if its left, right and itself is (the ancestor of) p / q, then it is the lowest ancestor. 