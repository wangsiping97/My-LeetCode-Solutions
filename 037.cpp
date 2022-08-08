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
    int row[9], col[9], blk[9]; // row[1] = (1000001110)2
    int result[9][9]; // result
    int origin[9][9]; // original values
    bool flag;
    int digits[1024];
    struct data {
        int x;
        int y;
        int blk;
        int value; // number of digits can be filled in this cell
    } prio[81];
private: 
    int countBits (int x) {
        int cnt = 0;
        while (x) {
            cnt += x & 1;
            x = x >> 1;
        }
        return cnt;
    }
    void dfs(int idx) {
        if (flag) return;
        if (idx == 81) {
            // write to origin
            flag = true;
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    origin[i][j] = result[i][j];
                }
            }
            return;
        }
        int x = prio[idx].x;
        int y = prio[idx].y;
        int blk_v = prio[idx].blk;
        int state = row[x] & col[y] & blk[blk_v]; // possible values
        if (origin[x][y] > 0) {
            result[x][y] = origin[x][y];
            dfs(idx+1);
            return;
        }
        for (int digit = 1; digit <= 9; ++digit) {
            if ((state & (1<<digit)) == 0)
                continue;
            result[x][y] = digit;
            row[x] ^= (1<<digit);
            col[y] ^= (1<<digit);
            blk[blk_v] ^= (1<<digit);
            dfs(idx+1);
            row[x] ^= (1<<digit);
            col[y] ^= (1<<digit);
            blk[blk_v] ^= (1<<digit);
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        // initialize digits
        for (int i = 1; i <= 9; ++i) {
            digits[1<<i] = i;
        }
        // initialize 
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                origin[i][j] = board[i][j] == '.' ? 0 : (board[i][j] - '0');
                result[i][j] = 0;
                prio[i * 9 + j].x = i;
                prio[i * 9 + j].y = j;
                prio[i * 9 + j].blk = (i/3) * 3 + (j/3);
            }
        }
        for (int i = 0; i < 9; ++i) {
            row[i] = 1022;
            col[i] = 1022;
            blk[i] = 1022;
        }
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (origin[i][j]) {
                    row[i] ^= (1<<origin[i][j]);
                    col[j] ^= (1<<origin[i][j]);
                    blk[(i/3) * 3 + (j/3)] ^= (1<<origin[i][j]);
                } 
            }
        }
        // initialize states
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (origin[i][j]) {
                    prio[i * 9 + j].value = 10000;
                } else {
                    prio[i * 9 + j].value = countBits(row[i] & col[j] & blk[(i/3) * 3 + (j/3)]);
                }
            }
        }
        // sort the cells by prio
        for (int i = 0; i < 81; ++i) {
            int min_idx = i;
            for (int j = i+1; j < 81; ++j) {
                if (prio[j].value < prio[min_idx].value) {
                    min_idx = j;
                }
            }
            std::swap(prio[i], prio[min_idx]);
            for (int j = i+1; j < 81; ++j) {
                if (prio[j].x == prio[i].x || 
                    prio[j].y == prio[i].y ||
                    prio[j].blk == prio[i].blk) {
                    prio[j].value--;
                }
            }
        }
        // run dfs
        flag = false;
        dfs(0);
        // write result to board
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                board[i][j] = origin[i][j] + '0';
            }
        }
        
    }
};