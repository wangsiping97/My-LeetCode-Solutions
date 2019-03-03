// Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.


#include <iostream> 
#include <vector> 
using namespace std;

class Solution {
public:
    int index(int i, int j) {
        int ind;
        if (i >= 0 && i <= 2 && j >= 0 && j <= 2)
            ind = 18;
        else if (i >= 0 && i <= 2 && j >= 3 && j <= 5)
            ind = 19;
        else if (i >= 0 && i <= 2 && j >= 6 && j <= 8)
            ind = 20;
        else if (i >= 3 && i <= 5 && j >= 0 && j <= 2)
            ind = 21;
        else if (i >= 3 && i <= 5 && j >= 3 && j <= 5)
            ind = 22;
        else if (i >= 3 && i <= 5 && j >= 6 && j <= 8)
            ind = 23;
        else if (i >= 6 && i <= 8 && j >= 0 && j <= 2)
            ind = 24;
        else if (i >= 6 && i <= 8 && j >= 3 && j <= 5)
            ind = 25;
        else
            ind = 26;
        return ind;
    }
    bool isValidSudoku(vector< vector<char> >& board) {
        int bucket[27][9];
        for (int i = 0; i < 27; i++) {
            for (int j = 0; j < 9; j++)
                bucket[i][j] = 0;
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] >= '1' && board[i][j] <= '9')
                {
                    bucket[i][board[i][j] - '0' - 1]++;
                    if (bucket[i][board[i][j] - '0' - 1] == 2) return false;
                    bucket[j + 9][board[i][j] - '0' - 1]++;
                    if (bucket[j + 9][board[i][j] - '0' - 1] == 2) return false;
                    bucket[index(i, j)][board[i][j] - '0' - 1]++;
                    if (bucket[index(i, j)][board[i][j] - '0' - 1] == 2) return false;
                }
            }
        }
        return true;
    }
};