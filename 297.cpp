// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

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
        se_helper(root, s);
        return s;
    }
    void se_helper(TreeNode* root, string& s) {
        if (!root) {
            s += "*.";
            return;
        }
        s = s + to_string(root->val) + ".";
        se_helper(root->left, s);
        se_helper(root->right, s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "*.") return NULL;
        vector<string> v;
        string temp;
        for (int i = 0; i < data.size(); ++i) {
            if (data[i] == '.') {
                v.push_back(temp);
                temp.clear();
            }
            else temp += data[i];
        }
        int i = 0;
        int &index = i;
        return de_helper(v, index);
    }
    TreeNode* de_helper(vector<string>& v, int& index) {
        if (index == v.size() || v[index] == "*") return NULL;
        TreeNode* node = new TreeNode(atoi(v[index].data())); 
        index ++;
        node->left = de_helper(v, index);
        index ++;
        node->right = de_helper(v, index);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));