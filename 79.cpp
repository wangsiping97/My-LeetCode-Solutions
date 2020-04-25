// Given a 2D board and a word, find if the word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

#include <string> 
#include <vector> 
#include <cstdlib> 
using namespace std; 

class Solution {
public:
    bool flag;
    void dfs(int index, vector< vector<char> >& board, int i, int j, string word) {
        if (flag) return;
        if (index == word.length()) {
            flag = true; 
            return; 
        }
        if (i < 0 || i == board.size()) return;
        if (j < 0 || j == board[0].size()) return; 
        if (board[i][j] != word[index]) return;
        board[i][j] = '1';
        dfs(index + 1, board, i + 1, j, word);
        if (flag) return;
        dfs(index + 1, board, i - 1, j, word);
        if (flag) return;
        dfs(index + 1, board, i, j + 1, word);
        if (flag) return;
        dfs(index + 1, board, i, j - 1, word);
        board[i][j] = word[index];
    }
    bool exist(vector< vector<char> >& board, string word) {
        int n = board.size();
        if (n == 0) return false;
        int m = board[0].size();
        int l = word.length();
        if (l == 0) return true;
        if (n * m < l) return false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0]) {
                    dfs(0, board, i, j, word);
                    if (flag == true) return true;
                }
            }
        }
        return false;
    }
};