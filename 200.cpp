// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

#include <vector> 
#include <queue> 
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0; 
        queue< pair<int, int> > q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    q.push(pair<int, int>(i, j));
                    grid[i][j] = '2';
                    while (!q.empty()) {
                        int sz = q.size();
                        for (int k = 0; k < sz; ++k) {
                            pair<int, int> cur = q.front();
                            q.pop();
                            int i = cur.first, j = cur.second;
                            for(int ii = i - 1; ii <= i + 1; ii += 2) {
                                if (ii >= 0 && ii < m && grid[ii][j] == '1') {
                                    q.push(pair<int, int>(ii, j));
                                    grid[ii][j] = '2';
                                }
                            }
                            for (int jj = j - 1; jj <= j + 1; jj += 2) {
                                if (jj >= 0 && jj < n && grid[i][jj] == '1') {
                                    q.push(pair<int, int>(i, jj));
                                    grid[i][jj] = '2';
                                }
                            }
                        }
                    }
                    ans++;
                }
            }
        }
        return ans;
    }
};