// Given a binary tree, return the vertical order traversal of its nodes values.
// For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).
// Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).
// If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.
// Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.

#include <iostream> 
#include <vector> 
#include <map> 
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
    map< int, map<int, vector<int> > > m;
    void preorder(TreeNode* root, int x, int y) {
        if (!root) return; 
        m[x][y].push_back(root->val);
        preorder(root->left, x - 1, y + 1);
        preorder(root->right, x + 1, y + 1);
    }
    vector< vector<int> > verticalTraversal(TreeNode* root) {
        vector< vector<int> > ans;
        if (!root) return ans; 
        preorder(root, 0, 0);
        map< int, map<int, vector<int> > >::iterator iter;
        for (iter = m.begin(); iter != m.end(); iter++) {
            map<int, vector<int> >::iterator miter;
            vector<int> temp;
            for (miter = iter->second.begin(); miter != iter->second.end(); miter++) {
                sort(miter->second.begin(), miter->second.end());
                for (int i = 0; i < miter->second.size(); ++i) temp.push_back(miter->second[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};