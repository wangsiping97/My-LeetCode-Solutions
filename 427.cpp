// Given a n * n matrix grid of 0's and 1's only. We want to represent the grid with a Quad-Tree.
// Return the root of the Quad-Tree representing the grid.
// Notice that you can assign the value of a node to True or False when isLeaf is False, and both are accepted in the answer.
// A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:
// val: True if the node represents a grid of 1's or False if the node represents a grid of 0's. 
// isLeaf: True if the node is leaf node on the tree or False if the node has the four children.

#include <vector> 
using namespace std; 

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* construct(vector< vector<int> >& grid) {
        int n = grid.size();
        if (n == 0) return NULL;
        Node* root = new Node();
        root = dfs(grid, n, 0, 0, root);
        return root;
    }
    Node* dfs(vector< vector<int> >& grid, int length, int i, int j, Node* root) {
        if (check(grid, length, i, j)) {
            root->isLeaf = 1;
            root->val = grid[i][j];
            return root;
        }
        root->topLeft = new Node();
        root->topLeft = dfs(grid, length / 2, i, j, root->topLeft);
        root->bottomLeft = new Node();
        root->bottomLeft = dfs(grid, length / 2, i + length / 2, j, root->bottomLeft);
        root->topRight = new Node();
        root->topRight = dfs(grid, length / 2, i, j + length / 2, root->topRight);
        root->bottomRight = new Node();
        root->bottomRight = dfs(grid, length / 2, i + length / 2, j + length / 2, root->bottomRight);
        return root;
    }
    bool check(vector< vector<int> >& grid, int length, int i, int j) {
        for (int ii = i; ii < i + length; ++ii) {
            for (int jj = j; jj < j + length; ++jj) {
                if (grid[ii][jj] != grid[i][j]) return false;
            }
        }
        return true;
    }
};