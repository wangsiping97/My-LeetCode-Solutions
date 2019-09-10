// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

#include <vector> 
using namespace std;

class Solution {
public:
    bool binomialSearch(vector<int>& num, int left, int right, int target) {
        if (left >= right && num[left] != target) return false;
        int mid = (left + right) / 2;
        if (target > num[mid]) return binomialSearch(num, mid + 1, right, target);
        if (target < num[mid]) return binomialSearch(num, left, mid - 1, target);
        else return true;
    }
    bool searchMatrix(vector< vector<int> >& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size(); // n >= 1
        if (n == 0) return false;
        int i = 0; 
        while (i < m && matrix[i][0] <= target) i++;
        if (i == 0) return false;
        return binomialSearch(matrix[i - 1], 0, n - 1, target);
    }
};