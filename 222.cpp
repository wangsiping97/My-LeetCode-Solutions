// Given a complete binary tree, count the number of nodes.

#include <iostream> 
#include <vector> 
#include <deque> 
#include <cmath>
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
    int countNodes(TreeNode* root) {
        if (!root) return 0; 
        int left = 0;
        TreeNode* temp = root;
        while (temp) {
            left++;
            temp = temp->left;
        }
        int right = 0;
        temp = root;
        while (temp) {
            right++;
            temp = temp->right;
        }
        if (left == right) return pow(2, left) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};