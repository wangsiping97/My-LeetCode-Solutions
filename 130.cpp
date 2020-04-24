// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
// A region is captured by flipping all 'O's into 'X's in that surrounded region.

#include <vector> 
#include <cstdlib> 
using namespace std; 

class Solution {
public:
    void dfs(int i, int j, vector< vector<char> >& board, int n, int m) {
        if (i < 0 || i == n) return;
        if (j < 0 || j == m) return;
        if (board[i][j] == 'X') return; 
        if (board[i][j] == 'A') return;
        board[i][j] = 'A';
        dfs(i + 1, j, board, n, m);
        dfs(i - 1, j, board, n, m);
        dfs(i, j + 1, board, n, m);
        dfs(i, j - 1, board, n, m);
    } 
    void solve(vector< vector<char> >& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ++j) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) { 
                    if (board[i][j] == 'O') {
                        dfs(i, j, board, n, m);
                    }
                }
            }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                board[i][j] = board[i][j] == 'A' ? 'O' : 'X';
            }
    }
};