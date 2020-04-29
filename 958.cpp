// Given a binary tree, determine if it is a complete binary tree.
// In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.


// Definition for a binary tree node.
#include <cstdlib> 
#include <deque> 
using namespace std; 
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
    bool isCompleteTree(TreeNode* root) {
        deque<TreeNode*> level;
        level.push_back(root);
        int flag = 0;
        while (!level.empty()) {
            TreeNode* t = level.front();
            level.pop_front();
            TreeNode* tleft = t->left;
            TreeNode* tright = t->right;
            if (tleft == nullptr && tright != nullptr) return false;
            if (tleft == nullptr && tright == nullptr ) {
                flag = 2;
                continue;
            }
            if (flag == 2) return false;
            level.push_back(tleft);
            if (tright == nullptr) {
                if (flag == 1) return false;
                flag = 1;
                continue;
            }
            if (flag == 1) return false;
            level.push_back(tright);
            flag = 0;
        }
        return true;
    }
};