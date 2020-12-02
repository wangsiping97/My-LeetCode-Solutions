// Given an NxM matrix of positive and negative integers, write code to find the submatrix with the largest possible sum.
// Return an array [r1, c1, r2, c2], where r1, c1 are the row number and the column number of the submatrix's upper left corner respectively, and r2, c2 are the row number of and the column number of lower right corner. If there are more than one answers, return any one of them.
// Note: This problem is slightly different from the original one in the book.

#include <vector> 
using namespace std; 

class Solution {
public:
    vector<int> getMaxMatrix(vector< vector<int> >& matrix) {
        vector<int> ans;
        int N = matrix.size();
        if (N == 0) return ans;
        int M = matrix[0].size();
        if (M == 0) return ans;
        ans.insert(ans.begin(), 4, 0);
        int max = INT_MIN;
        int subsum[M];
        for (int i = 0; i < N; ++i) {
            memset(subsum, 0, M * sizeof(int));
            for (int j = i; j < N; ++j) {
                vector<int> tmparray;
                int cur = 0, max_subarray = INT_MIN, left = 0,right = 0;
                int Left[M];
                Left[0] = 0;
                for (int col = 0; col < M; ++col) {
                    subsum[col] += matrix[j][col]; //我们只是不断增加其高，也就是下移矩阵下边，所有这个矩阵每列的和只需要加上新加的那一行的元素
                    if (cur <= 0) {
                        cur = subsum[col];
                        Left[col] = col;
                    } else {
                        cur += subsum[col];
                        Left[col] = Left[col - 1];
                    }
                    if (max_subarray <= cur) {
                        max_subarray = cur;
                        left = Left[col];
                        right = col;
                    }
                }
                if (max < max_subarray) {
                    max = max_subarray;
                    ans[0] = i;
                    ans[1] = left;
                    ans[2] = j;
                    ans[3] = right;
                }
            }
        }
        return ans;
    }
};