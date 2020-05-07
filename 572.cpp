// Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

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
    bool isSame(TreeNode* sub_s, TreeNode* t) {
        if (sub_s == NULL && t != NULL) return false; 
        if (sub_s != NULL && t == NULL) return false; 
        if (sub_s == NULL && t == NULL) return true; 
        if (sub_s->val != t->val) return false; 
        return (isSame(sub_s->left, t->left)) && (isSame(sub_s->right, t->right)); 
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL) return false; 
        if (s->val == t->val && isSame(s, t)) return true; 
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};