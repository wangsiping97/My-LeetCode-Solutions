// Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
// Basically, the deletion can be divided into two stages:
// Search for a node to remove.
// If the node is found, delete the node.
// Note: Time complexity should be O(height of tree).

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
    TreeNode* parent;
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root->val == key) {
            if (root->right == NULL) return root->left; 
            if (root->left == NULL) return root->right; 
            TreeNode* t = root->right; 
            while (t->left) t = t->left; 
            t->left = root->left;
            return root->right; 
        }
        parent = root;
        TreeNode* node = search(root, key); 
        if (node == NULL) return root;
        if (parent->right == node) {
            if (node->right == NULL) {
                parent->right = node->left;
                return root; 
            }
            parent->right = node->right; 
            TreeNode* t = node->right; 
            while (t->left) t = t->left; 
            t->left = node->left; 
            return root; 
        }
        else {
            if (node->right == NULL) {
                parent->left = node->left;
                return root;
            }
            parent->left = node->right;
            TreeNode* t = node->right; 
            while (t->left) t = t->left; 
            t->left = node->left; 
            return root;
        }
    }
    
    TreeNode* search(TreeNode* root, int key) {
        if (root == NULL) return NULL; 
        if (root->val == key) return root; 
        parent = root;
        if (root->val > key) return search(root->left, key);
        else return search(root->right, key);
    }
};