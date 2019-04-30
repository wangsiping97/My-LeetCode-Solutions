// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
// Now consider if some obstacles are added to the grids. How many unique paths would there be?

#include <iostream> 
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector< vector<int> >& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        long long path[m][n];
        path[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 0 && path[i - 1][0] == 1) path[i][0] = 1;
            else path[i][0] = 0;
        }
        for (int i = 1; i < n; ++i) {
            if (obstacleGrid[0][i] == 0 && path[0][i - 1] == 1) path[0][i] = 1;
            else path[0][i] = 0;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) path[i][j] = 0;
                else path[i][j] = path[i - 1][j] + path[i][j - 1];
            }
        }
        return path[m - 1][n - 1];
    }
};