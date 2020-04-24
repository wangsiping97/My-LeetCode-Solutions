// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

#include <vector> 
#include <cstdlib> 
using namespace std;

class Solution {
public:
    bool** searched;
    void dfs(int i, int j, vector< vector<char> >& grid, int n, int m) {
        // boarder
        if (i == n || i < 0) return;
        if (j == m || j < 0) return;
        // water
        if (grid[i][j] == '0') return;
        // searched
        if (searched[i][j] == true) return;
        // island
        searched[i][j] = true;
        dfs(i + 1, j, grid, n, m);
        dfs(i - 1, j, grid, n, m);
        dfs(i, j + 1, grid, n, m);
        dfs(i, j - 1, grid, n, m);

    }
    int numIslands(vector< vector<char> >& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        searched = (bool**)malloc(n * sizeof(bool*));
        for (int i = 0; i < n; ++i) {
            searched[i] = (bool*)malloc(m * sizeof(bool));
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) 
                    searched[i][j] = false;
        }
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1' && searched[i][j] == false) {
                    count++;
                    dfs(i, j, grid, n, m);
                }
            }
        }
        return count;
    }
};