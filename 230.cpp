// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
// Note:
// You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st; 
        TreeNode* t = root;
        int count = 0;
        while (t != NULL || !st.empty()) {
            while (t) {
                st.push(t);
                t = t->left;
            }
            if (!st.empty()) {
                t = st.top();
                st.pop();
                count++;
                if (count == k) return t->val;
                t = t->right;
            }
        }
        return 0;
    }
};