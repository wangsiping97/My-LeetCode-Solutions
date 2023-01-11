// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
// An example is the root-to-leaf path 1->2->3 which represents the number 123.
// Find the total sum of all root-to-leaf numbers.
// Note: A leaf is a node with no children.

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int ans;
    void dfs(TreeNode *root, int tempSum)
    {
        if (!root)
            return;
        tempSum *= 10;
        tempSum += root->val;
        if (root->left)
            dfs(root->left, tempSum);
        if (root->right)
            dfs(root->right, tempSum);
        if (!root->left && !root->right)
            ans += tempSum;
    }
    int sumNumbers(TreeNode *root)
    {
        ans = 0;
        dfs(root, 0);
        return ans;
    }
};