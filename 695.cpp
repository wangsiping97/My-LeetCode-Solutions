// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
// Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

#include <vector> 
using namespace std; 

class Solution {
public:
    int maxsize;
    void dfs(int i, int j, vector< vector<int> >& grid, int n, int m, int& tempsize) {
        if (i < 0 || i == n) return; 
        if (j < 0 || j == m) return;
        if (grid[i][j] == 0) return; 
        grid[i][j] = 0;
        tempsize++;
        dfs(i + 1, j, grid, n, m, tempsize);
        dfs(i - 1, j, grid, n, m, tempsize);
        dfs(i, j + 1, grid, n, m, tempsize);
        dfs(i, j - 1, grid, n, m, tempsize);
    }
    int maxAreaOfIsland(vector< vector<int> >& grid) {
        maxsize = 0;
        int tempsize = 0;
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    tempsize = 0;
                    dfs(i, j, grid, n, m, tempsize);
                    maxsize = maxsize > tempsize ? maxsize : tempsize;
                }
            }
        }
        return maxsize;
    }
};