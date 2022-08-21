// Given an m x n board of characters and a list of strings words, return all words on the board.
// Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

#include <vector> 
#include <string> 
#include <unordered_map> 
using namespace std; 

class TrieNode {
public: 
    bool isLeaf;
    bool isOut;
    string word;
    unordered_map<char, TrieNode*> children;
    TrieNode() {
        isLeaf = false;
        isOut = false;
    }
};

class Trie {
private: 
    TrieNode* root;
public: 
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* p = root;
        for (char c : word) {
            if (p->children.find(c) == p->children.end()) {
                p->children[c] = new TrieNode();
                p = p->children[c];
            } else {
                p = p->children[c];
            }
        }
        p->word = word;
        p->isLeaf = true;
    }
    TrieNode* getRoot() {
        return root;
    }
};

class Solution {
public:
    vector<string> ans;
    vector<vector<char>> visited;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie = Trie();
        for (string word : words) {
            trie.insert(word);
        }
        int m = board.size();
        int n = board[0].size();
        visited = board;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                visited[i][j] = '-';
        }
        // start search
        TrieNode* root = trie.getRoot();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (root->children.find(board[i][j]) != root->children.end()) {
                    visited[i][j] = '+';
                    dfs(board, root->children[board[i][j]], i, j);
                    visited[i][j] = '-';
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& board, TrieNode* node, int i, int j) {
        if (node->isLeaf) {
            if (node->isOut == false) {
                ans.emplace_back(node->word);
                node->isOut = true;
            }
        }
        if (node->children.size() == 0) {
            return;
        }

        helper(board, node, i, j-1);
        helper(board, node, i, j+1);
        helper(board, node, i-1, j);
        helper(board, node, i+1, j);

    }

    void helper(vector<vector<char>>& board, TrieNode* node, int i, int j) {
        if (i < 0 || i == board.size() || j < 0 || j == board[0].size())
            return;
        if (node->children.find(board[i][j]) == node->children.end())
            return;
        if (visited[i][j] == '+')
            return;
        visited[i][j] = '+';
        dfs(board, node->children[board[i][j]], i, j);
        visited[i][j] = '-';
    }
};