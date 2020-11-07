// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
// Example 1:
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]

// Example 2:
// Input:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector< vector<int> >& matrix) {
        int flag = 1; // go
        vector<int> ans;
        int m = matrix.size();
        if (m == 0) return ans;
        int n = matrix[0].size();
        int left = 0, right = n - 1, up = 0, down = m - 1;
        int count = 0;
        while (1) {
            for (int j = left; j <= right; ++j) ans.push_back(matrix[up][j]);
            count += right - left + 1;
            if (count == m * n) break;
            up++;
            for (int i = up; i <= down; ++i) ans.push_back(matrix[i][right]);
            count += down - up + 1;
            if (count == m * n) break;
            right--;
            for (int j = right; j >= left; --j) ans.push_back(matrix[down][j]);
            count += right - left + 1;
            if (count == m * n) break;
            down--;
            for (int i = down; i >= up; --i) ans.push_back(matrix[i][left]);
            count += down - up + 1;
            if (count == m * n) break;
            left++;
        }
        return ans;
    }
};