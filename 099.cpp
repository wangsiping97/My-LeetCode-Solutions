// Two elements of a binary search tree (BST) are swapped by mistake.
// Recover the tree without changing its structure.

#include <iostream> 
#include <vector> 
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
    void recoverTree(TreeNode* root) {
        if (root == NULL) return;
        TreeNode *cur, *pre;
        TreeNode *parent = NULL, *first = NULL, *second = NULL; 
        cur = root; 
        while (cur) {
            if (!cur->left) {
                if (parent && parent->val > cur->val) {
                    if (first == NULL) first = parent; 
                    second = cur;
                }
                parent = cur; // 这次取出的数
                cur = cur->right;
            }
            else {
                pre = cur->left; 
                while (pre->right && pre->right != cur) pre = pre->right; 
                if (!pre->right) {
                    pre->right = cur; 
                    cur = cur->left;
                }
                else {
                    pre->right = NULL; 
                    if (parent && parent->val > cur->val) {
                        if (first == NULL) first = parent;
                        second = cur;
                    }
                    parent = cur; 
                    cur = cur->right;
                }
            }
        }
        if (first && second) swap(first->val, second->val);
        return;
    }
};

// Morris Traversal 