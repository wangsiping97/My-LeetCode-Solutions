// Given the root of a binary tree, each node in the tree has a distinct value.
// After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
// Return the roots of the trees in the remaining forest.  You may return the result in any order.

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
    vector<TreeNode*> ans;
    TreeNode* postorder(TreeNode* root, vector<int>& to_delete) {
        if (!root) return NULL;
        // important!
        root->left = postorder(root->left, to_delete);
        root->right = postorder(root->right, to_delete);
        
        for (int i = 0; i < to_delete.size(); ++i) {
            if (root->val == to_delete[i]) {
                if (root->left) ans.push_back(root->left);
                if (root->right) ans.push_back(root->right);
                root = NULL;
                break;
            }
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        int i;
        for (i = 0; i < to_delete.size(); ++i) {
            if (root->val == to_delete[i]) break;
        }
        if (i == to_delete.size()) ans.push_back(root);
        postorder(root, to_delete);
        return ans;
    }
};

// Solution
// postorder
// dong't need to find the parent node!