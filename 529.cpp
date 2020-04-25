// You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.

// Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this position according to the following rules:

// If a mine ('M') is revealed, then the game is over - change it to 'X'.
// If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
// If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
// Return the board when no more squares will be revealed.

#include <vector> 
using namespace std; 

class Solution {
public:
    void dfs(int i, int j, vector< vector<char> >& board, int n, int m) {
        if (i < 0 || i == n) return;
        if (j < 0 || j == m) return;
        if (board[i][j] == 'E') {
            int num = 0;
            for (int ii = i - 1; ii <= i + 1; ++ii)
                for (int jj = j - 1; jj <= j + 1; ++jj) 
                    if (ii >= 0 && ii < n && jj >= 0 && jj < m)
                        if (board[ii][jj] == 'M') num++;
            if (num == 0) {
                board[i][j] = 'B';
                dfs(i + 1, j, board, n, m);
                dfs(i - 1, j, board, n, m);
                dfs(i, j + 1, board, n, m);
                dfs(i, j - 1, board, n, m);
                dfs(i - 1, j - 1, board, n, m);
                dfs(i - 1, j + 1, board, n, m);
                dfs(i + 1, j - 1, board, n, m);
                dfs(i + 1, j + 1, board, n, m);
            }
            else board[i][j] = num + '0';
        }
    }
    vector< vector<char> > updateBoard(vector< vector<char> >& board, vector<int>& click) {
        int n = board.size(); 
        if (n == 0) return board; 
        int m = board[0].size(); 
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        dfs(click[0], click[1], board, n, m);
        return board; 
    }
};