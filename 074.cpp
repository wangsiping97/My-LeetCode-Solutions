// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

#include <vector> 
using namespace std;

class Solution {
public:
    bool searchMatrix(vector< vector<int> >& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size(); // n >= 1
        if (n == 0) return false;
        int o = 0, p = n * m - 1, mid;
        while (o <= p) {
            int i, j;
            mid = (o + p) >> 1;
            j = mid % n;
            i = (mid - j) /n;
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] < target) o = mid + 1;
            else p = mid - 1;
        }
        return false;
    }
};