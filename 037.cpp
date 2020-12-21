// Write a program to solve a Sudoku puzzle by filling the empty cells.
// A sudoku solution must satisfy all of the following rules:
// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

#include <vector> 
#include <iostream> 
using namespace std; 

class Solution {
public:
    bool row[9][9];
    bool col[9][9];
    bool block[3][3][9];
    vector< vector<char> > ans;
    vector< pair<int, int> > spaces; // important
    void solveSudoku(vector< vector<char> >& board) {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(block, 0, sizeof(block));
        ans = board;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    row[i][board[i][j] - '1'] = true;
                    col[j][board[i][j] - '1'] = true;
                    int bi = i / 3, bj = j / 3;
                    block[bi][bj][board[i][j] - '1'] = true;
                } else {
                    spaces.push_back(pair<int, int>(i, j));
                }
            }
        }
        dfs(board, 0);
        board = ans;
    }

    void dfs(vector< vector<char> >& board, int pos) {
        if (pos == spaces.size()) {
            ans = board;
            return;
        }
        int i = spaces[pos].first, j = spaces[pos].second;
        for (int k = 0; k < 9; ++k) {
            if (!row[i][k] && !col[j][k] && !block[i / 3][j / 3][k]) {
                board[i][j] = k + '1';
                row[i][k] = col[j][k] = block[i / 3][j / 3][k] = true;
                dfs(board, pos + 1);
                row[i][k] = col[j][k] = block[i / 3][j / 3][k] = false;
            }
        }
    }
};