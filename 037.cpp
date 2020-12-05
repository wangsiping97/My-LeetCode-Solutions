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
private:
    bool row[9][9];
    bool col[9][9];
    bool block[9][9];
    bool valid;
    vector< pair<int, int> > spaces;

public:
    void dfs(vector< vector<char> >& board, int pos) {
        if (pos == spaces.size()) {
            valid = true;
            return;
        }

        int i = spaces[pos].first;
        int j = spaces[pos].second;
        for (int val = 1; val <= 9 && !valid; ++val) {
            if (row[i][val - 1] == 0 && col[val - 1][j] == 0 && block[i / 3 * 3 + j / 3][val - 1] == 0) {
                board[i][j] = val + '0';
                row[i][val - 1] = col[val - 1][j] = block[i / 3 * 3 + j / 3][val - 1] = 1;
                dfs(board, pos + 1);
                row[i][val - 1] = col[val - 1][j] = block[i / 3 * 3 + j / 3][val - 1] = 0;
            }
        }
    }

    void solveSudoku(vector< vector<char> >& board) {
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(block, false, sizeof(block));
        valid = false;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    spaces.push_back(pair<int, int>(i, j));
                }
                else {
                    row[i][board[i][j] - '1'] = col[board[i][j] - '1'][j] = block[i / 3 * 3 + j / 3][board[i][j] - '1'] = true;
                }
            }
        }

        dfs(board, 0);
    }
};
