// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.
 
#include <vector> 

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0, col = n-1;
        while (row < m && col >= 0) {
            if (matrix[row][col] == target) return true;
            while (col >= 0 && matrix[row][col] > target) col--;
            if (col < 0) return false;
            if (matrix[row][col] == target) return true;
            while (row < m && matrix[row][col] < target) row++;
            if (row == m) return false;
            if (matrix[row][col] == target) return true;
        }
        return false;
    }
};