// Given an integer matrix, find the length of the longest increasing path.
// From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

#include <vector> 
#include <unordered_map> 
#include <cstdlib>
using namespace std; 

class Solution {
public:
    int ans;
    vector<vector<int> > memo;
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        ans = 0;
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        memo.resize(m);
        for (int i = 0; i < m; ++i) {
            memo[i].resize(n);
            for (int j = 0; j < n; ++j) {
                memo[i][j] = 0;
            }
        }
        // dfs
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(matrix, i, j, m, n));
            }
        }
        return ans;
    }
    int dfs(vector<vector<int> >& matrix, int i, int j, int m, int n) {
        if (memo[i][j] != 0) return memo[i][j];
        if (memo[i][j] == 0) memo[i][j] = 1;
        for (int ii = i - 1; ii <= i + 1; ii += 2) {
            if (ii < 0 || ii >= m) continue;
            if (matrix[ii][j] > matrix[i][j]) {
                memo[i][j] = max(memo[i][j], 1 + dfs(matrix, ii, j, m, n));
            }
        }
        for (int jj = j - 1; jj <= j + 1; jj += 2) {
            if (jj < 0 || jj >= n) continue;
            if (matrix[i][jj] > matrix[i][j]) {
                memo[i][j] = max(memo[i][j], 1 + dfs(matrix, i, jj, m, n));
            }
        }
        return memo[i][j];
    }
};

// Solution : dfs + memo