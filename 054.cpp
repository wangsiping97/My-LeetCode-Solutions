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
        
        int m = matrix.size();
        if (m == 0) return ans;
        if (m == 1) return matrix[0];
        int n = matrix[0].size();
        if (n == 0) return ans;
        if (n == 1) {
            for (int i = 0; i < m; ans.push_back(matrix[i][0]),i++);
            return ans;
        }
		
		int i=0, j=0, p=1;
        int i_ = i, j_ = j;
		
        while (p <= n && p <= m) {
            for (; i < n-p; ans.push_back(matrix[j][i]), i++);
            if (i_ == i) break;
            i_ = i;
            for (; j < m-p; ans.push_back(matrix[j][i]), j++);
            if (j == j_) break;
            j_ = j;
            for (; i > p-1; ans.push_back(matrix[j][i]), i--);
            if (i == i_) break;
            i_ = i;
            for (; j > p; ans.push_back(matrix[j][i]), j--);
            if (j_ == j) break;
            j_ = j;
            p++;
        }
        ans.push_back(matrix[j][i]);
		
        return ans;
		
    }
};