// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
// Note: A leaf is a node with no children.

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

typedef pair<TreeNode*, int> P;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0; 
        deque< pair<TreeNode*, int> >q; 
        P p0(root, 1);
        q.push_back(p0);
        q.pop_front();
        while (!q.empty()) {
            P top = q.front();
            if (top.first->left == NULL && top.first->right == NULL) {
                return top.second;
            }
            if (top.first->left != NULL) {
                P left(top.first->left, top.second + 1);
                q.push_back(left);
            }
            if (top.first->right != NULL) {
                P right(top.first->right, top.second + 1);
                q.push_back(right);
            }
        }
        return -1;
    }
};

// Solution
// BFS: 只要碰到第一个没有孩子节点的节点，这个节点的深度就是整个树的最小深度。