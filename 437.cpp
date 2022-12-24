// You are given a binary tree in which each node contains an integer value.
// Find the number of paths that sum to a given value.
// The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
// The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

#include <iostream>
#include <vector>
#include <unordered_map>
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
    int pathSumWithRoot(TreeNode *root, long long targetSum)
    {
        if (!root)
            return 0;
        int found = (root->val == targetSum);
        return found + pathSumWithRoot(root->left, targetSum - root->val) + pathSumWithRoot(root->right, targetSum - root->val);
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;
        return pathSum(root->left, targetSum) + pathSum(root->right, targetSum) + pathSumWithRoot(root, targetSum);
    }
};