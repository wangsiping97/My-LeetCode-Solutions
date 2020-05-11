// Given a binary tree, flatten it to a linked list in-place.

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
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode* cur = root; 
        TreeNode* pre = NULL;
        while (cur) {
            if (!cur->left) {
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
                    TreeNode* right = cur->right; 
                    TreeNode* left = cur->left; 
                    cur->left = NULL; 
                    cur->right = left; 
                    pre->right = right; 
                    cur = cur->right; 
                }
            }
        }
    }
};

// Solution
// 找到最左子节点，然后回到其父节点，把其父节点和右子节点断开，将原左子结点连上父节点的右子节点上，然后再把原右子节点连到新右子节点的右子节点上，然后再回到上一父节点做相同操作