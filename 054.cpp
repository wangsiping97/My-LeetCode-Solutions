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

#include <iostream> 
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector< vector<int> >& matrix) {
        vector<int> ans;
        int i=0, j=0, p=1;
        int m = matrix.size();
        if (m == 0) return ans;
        int n = matrix[0].size();
        if (n == 0) return ans;
        while (p < n || p < m) {
            while (i < n-p) {
                ans.push_back(matrix[j][i]);
                i++;
            }
            while (j < m-p) {
                ans.push_back(matrix[j][i]);
                j++;
            }
            while (i > p-1) {
                ans.push_back(matrix[j][i]);
                i--;
            }
            while (j > p) {
                ans.push_back(matrix[j][i]);
                j--;
            }
            p++;
        }
        return ans;
    }
};