// Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
// The distance between two adjacent cells is 1.

#include <vector> 
using namespace std; 

class Solution {
public:
    vector< vector<int> > updateMatrix(vector< vector<int> >& matrix) {
        int m = matrix.size();
        if (m == 0) return matrix;
        int n = matrix[0].size();
        if (n == 0) return matrix; 
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) count++;
                if (matrix[i][j] == 1) matrix[i][j] = -1;
            }
        }
        int level = 1;
        while (count < m * n) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (matrix[i][j] != -1) continue;
                    for (int ii = i - 1; ii <= i + 1; ++ii) 
                        if (ii >= 0 && ii < m && matrix[ii][j] == level - 1) 
                            matrix[i][j] = level;
                    for (int jj = j - 1; jj <= j + 1; ++jj) 
                        if (jj >= 0 && jj < n && matrix[i][jj] == level - 1) 
                            matrix[i][j] = level;
                    if (matrix[i][j] != -1) count++;
                }
            }
            level++;
        }
        return matrix;
    }
};