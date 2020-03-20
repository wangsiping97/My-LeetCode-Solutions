// Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:
// You receive a valid board, made of only battleships or empty slots.
// Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
// At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.

#include <string> 
#include <vector> 
using namespace std; 

class Solution {
public:
    int m;
    int n;
    int countBattleships(vector< vector<char> >& board) {
        int ans = 0;
        m = board.size();
        if (m == 0) return 0;
        n = board[0].size();
        if (n == 0) return 0;
        int checked[m][n];
        for (int i = 0; i < m; ++i) {
            memset(checked[i], 0, n * 4);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X' && checked[i][j] == 0) {
                    checked[i][j] = 1;
                    ans++;
                    int temp = 1;
                    while (i - temp >= 0 && board[i - temp][j]== 'X') {
                        checked[i - temp][j] = 1;
                        temp++;
                    }
                    if (temp != 1) continue;
                    while (i + temp < m && board[i + temp][j]== 'X') {
                        checked[i + temp][j] = 1;
                        temp++;
                    }
                    if (temp != 1) continue;
                    while (j - temp >= 0 && board[i][j - temp]== 'X') {
                        checked[i][j - temp] = 1;
                        temp++;
                    }
                    if (temp != 1) continue;
                    while (j + temp < n && board[i][j + temp]== 'X') {
                        checked[i][j + temp] = 1;
                        temp++;
                    }
                }
            }
        }
        return ans;
    }
};