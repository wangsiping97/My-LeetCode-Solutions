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
    unordered_map<char, TrieNode*> next;
    TrieNode () {
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
        TrieNode* cur = root; 
        for (char c : word) {
            if (cur->next.count(c) == 0) {
                cur->next[c] = new TrieNode();
                cur->next[c]->word = cur->word + c;
            }
            cur = cur->next[c];
        }
        cur->isLeaf = true;
    }
    TrieNode* getRoot() {
        return root;
    }
}; 

class Solution {
public:
    vector<string> ans; 
    vector< vector<char> > visited;
    vector<string> findWords(vector< vector<char> >& board, vector<string>& words) {
        visited = board;
        Trie trie = Trie();
        TrieNode* root = trie.getRoot();
        for (string word : words) trie.insert(word);
        int m = board.size();
        if (m == 0) return ans;
        int n = board[0].size();
        if (n == 0) return ans; 
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (root->next.count(board[i][j]) > 0) {
                    visited[i][j] = '-';
                    dfs(board, root->next[board[i][j]], i, j);
                    visited[i][j] = '+';
                }
            }
        }
        return ans;
    }
    void dfs(vector< vector<char> >& board, TrieNode* node, int i, int j) {
        if (!node) return;
        if (node->isLeaf && !node->isOut) {
            ans.push_back(node->word);
            node->isOut = true;
        }
        for (int ii = i - 1; ii <= i + 1; ii += 2) {
            if (ii >= 0 && ii < board.size() && node->next.count(board[ii][j]) > 0 && visited[ii][j] != '-') {
                visited[ii][j] = '-';
                dfs(board, node->next[board[ii][j]], ii, j);
                visited[ii][j] = '+';
            }
        }
        for (int jj = j - 1; jj <= j + 1; jj += 2) {
            if (jj >= 0 && jj < board[0].size() && node->next.count(board[i][jj]) > 0 && visited[i][jj] != '-') {
                visited[i][jj] = '-';
                dfs(board, node->next[board[i][jj]], i, jj);
                visited[i][jj] = '+';
            } 
        }
    }
};