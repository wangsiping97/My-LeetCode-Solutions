// Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

// Example:
// Input: 3
// Output:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

#include <iostream> 
#include <vector> 
using namespace std;

class Solution {
public:
    vector< vector<int> > generateMatrix(int n) {
        // from c++ primer: the initialization of two-dimensional array
        // if .reserve() is used, do not use '[]' to access elements (segment fault)
        vector< vector<int> > ans(n, vector<int>());
        for (int i = 0; i < n; i++) {
            ans[i].resize(n);
        }

        int i=0, j=0, p=1;
        int i_ = i, j_ = j;
        int value = 1;

        while (p <= n) {
            for (; i < n-p; ans[p - 1][i] = value, ++i, ++value);
            if (i_ == i) break;
            i_ = i;
            for (; j < n-p; ans[j][n - p] = value, ++j, ++value);
            if (j == j_) break;
            j_ = j;
            for (; i > p-1; ans[n - p][i] = value, --i, ++value);
            if (i == i_) break;
            i_ = i;
            for (; j > p; ans[j][p - 1] = value, --j, ++value);
            if (j_ == j) break;
            j_ = j;
            p++;
        }
        ans[j][i] = value;
        return ans;
    }
};