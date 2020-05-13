// Given postorder and inorder traversal of a tree, construct the binary tree.
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        if (n == 0) return NULL; 
        TreeNode* root = new TreeNode(postorder[n - 1]);
        vector<int> inleft, inright, postleft, postright;
        int flag = 0;
        for (int i = 0; i < n; ++i) {
            if (inorder[i] == postorder[n - 1]) {
                flag = 1;
                continue;
            }
            if (flag == 0) {
                inleft.push_back(inorder[i]);
                postleft.push_back(postorder[i]);
            } else {
                inright.push_back(inorder[i]);
                postright.push_back(postorder[i - 1]);
            }
        }
        root->left = buildTree(inleft, postleft);
        root->right = buildTree(inright, postright);
        return root;
    }
};