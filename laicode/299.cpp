// Find distance between two given keys of a Binary Tree, no parent pointers are given. Distance between two nodes is the minimum number of edges to be traversed to reach one node from other.

#include <iostream> 
using namespace std; 

class TreeNode {
public:
 int value;
 TreeNode* left;
 TreeNode* right;
 TreeNode(int v) : value(v), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* parent;
    int p1, p2, p_parent;
    int distance(TreeNode* root, int k1, int k2) {
        find(root, k1, k2, 0);
        return p1 + p2 - 2 * p_parent;
    }
    int find (TreeNode* node, int k1, int k2, int temp) {
        int mid = 0;
        if (!node) return 0;
        if (node->value == k1) {
            mid = 1;
            p1 = temp;
        }
        if (node->value == k2) {
            mid = 1;
            p2 = temp;
        }
        int left = find(node->left, k1, k2, temp + 1);
        int right = find(node->right, k1, k2, temp + 1);
        if (left + right + mid >= 2) {
            parent = node; 
            p_parent = temp;
        }
        return mid + left + right > 0 ? 1 : 0;
  }
};
