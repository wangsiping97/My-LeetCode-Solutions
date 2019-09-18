// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

#include <vector> 
using namespace std;

class Solution {
public:
    void setZeroes(vector< vector<int> >& matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        if (n == 0) return;
        vector<int> line;
        vector<int> row;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j)
                if (matrix[i][j] == 0) {
                    line.push_back(i);
                    row.push_back(j);
                }
        for (int i = 0; i < line.size(); ++i) 
            for (int j = 0; j < n; ++j) 
                matrix[line[i]][j] = 0;
        for (int i = 0; i < row.size(); ++i) 
            for (int j = 0; j < m; ++j) 
                matrix[j][row[i]] = 0;
    }
};