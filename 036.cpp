// Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.


#include <iostream> 
#include <vector> 
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9];
        int col[9][9];
        int block[9][9];
        memset(row, 0, 81 * sizeof(int));
        memset(col, 0, 81 * sizeof(int));
        memset(block, 0, 81 * sizeof(int));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (++row[i][board[i][j] - '1'] >= 2) return false;
                    if (++col[board[i][j] - '1'][j] >= 2) return false;
                    int block_i = i / 3;
                    int block_j = j / 3;
                    if (++block[block_i * 3 + block_j][board[i][j] - '1'] >= 2) return false;
                }
            }
        }
        return true;
    }
};