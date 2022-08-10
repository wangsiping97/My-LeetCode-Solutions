// Given a 2D matrix matrix, handle multiple queries of the following type:

// Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
// Implement the NumMatrix class:

// NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
// int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
// You must design an algorithm where sumRegion works on O(1) time complexity.

#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
    int dp[201][201];
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        memset(dp, 0, sizeof(dp));
        dp[0][0] = matrix[0][0];
        for (int i = 1; i < n; ++i) {
            dp[0][i] = dp[0][i-1] + matrix[0][i];
        }
        for (int j = 1; j < m; ++j) {
            dp[j][0] = dp[j-1][0] + matrix[j][0];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int r2c2 = dp[row2][col2];
        int tmp1 = row1 == 0 ? 0 : dp[row1-1][col2];
        int tmp2 = col1 == 0 ? 0 : dp[row2][col1-1];
        int tmp3 = row1 == 0 || col1 == 0 ? 0 : dp[row1-1][col1-1];
        return r2c2 - tmp1 - tmp2 + tmp3;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */