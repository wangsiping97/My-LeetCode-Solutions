// Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
// Calling next() will return the next smallest number in the BST.

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

class BSTIterator {
public:
    TreeNode* node;
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        node = root;
        while (node) {
            st.push(node);
            node = node->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        node = st.top();
        int k = node->val;
        st.pop();
        node = node->right;
        while (node) {
            st.push(node);
            node = node->left;
        }
        return k;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */