// We are given a binary tree (with root node root), a target node, and an integer value K.
// Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

#include <iostream> 
#include <vector> 
#include <deque> 
#include <unordered_map> 
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> ans; 
        if (!root) return ans;
        unordered_map< int, vector<int> > graph;
        unordered_map<int, int> checked;
        deque<TreeNode*> q; 
        deque<int> bfs;
        q.push_back(root);
        while (!q.empty()) {
            TreeNode* top = q.front();
            q.pop_front();
            if (top->left) {
                graph[top->val].push_back(top->left->val);
                graph[top->left->val].push_back(top->val);
                q.push_back(top->left);
            }
            if (top->right) {
                graph[top->val].push_back(top->right->val);
                graph[top->right->val].push_back(top->val);
                q.push_back(top->right);
            }
        }
        bfs.push_back(target->val);
        while (!bfs.empty()) {
            if (K == 0) {
                for (int val : bfs) {
                    ans.push_back(val);
                }
                return ans;
            }
            K--;
            int sz = bfs.size();
            for (int i = 0; i < sz; ++i) {
                int top = bfs.front();
                checked[top] = 1;
                bfs.pop_front();
                for(int val : graph[top]) {
                    if (checked[val] != 1) {
                        checked[val] = 1;
                        bfs.push_back(val);
                    }
                }
            }
        }
        return ans;
    }
};

// Solution
// change the tree to a graph, then use bfs. 