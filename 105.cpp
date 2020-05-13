// Given preorder and inorder traversal of a tree, construct the binary tree.
// Note:
// You may assume that duplicates do not exist in the tree.

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        vector<int> preleft, inleft, preright, inright;
        int flag = 0;
        for (int i = 0; i <inorder.size(); ++i) {
            if (inorder[i] == preorder[0]) {
                flag = 1;
                continue;
            }
            if (flag == 0) {
                inleft.push_back(inorder[i]);
                preleft.push_back(preorder[i + 1]);
            }
            else {
                inright.push_back(inorder[i]);
                preright.push_back(preorder[i]);
            }
        }
        root->left = buildTree(preleft, inleft);
        root->right = buildTree(preright, inright);
        return root;
    }
};