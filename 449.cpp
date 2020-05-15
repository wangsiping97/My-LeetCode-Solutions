// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
// Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.
// The encoded string should be as compact as possible.
// Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if (!root) return s; 
        se_helper(root, s);
        return s;
    }
    void se_helper(TreeNode* root, string& s) {
        if (!root) return;
        s = s + to_string(root->val) + " ";
        se_helper(root->left, s);
        se_helper(root->right, s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL; 
        TreeNode* root = NULL;
        string val;
        for (int i = 0; i < data.length(); ++i) {
            if (data[i] == ' ') {
                int value = atoi(val.data());
                val.clear();
                if (!root) {
                    root = new TreeNode(value);
                    continue;
                }
                de_helper(root, value);
            }
            else val += data[i];
        }
        return root;
    }
    void de_helper(TreeNode* root, int val) {
        if (root->val > val) {
            if (!root->left) root->left = new TreeNode(val);
            else return de_helper(root->left, val);
        }
        else {
            if (!root->right) root->right = new TreeNode(val);
            else return de_helper(root->right, val);
        }
    }
};

// Solution
// preorder (dfs)