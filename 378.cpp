// Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

// Note that it is the kth smallest element in the sorted order, not the kth distinct element.

// You must find a solution with a memory complexity better than O(n2).

#include <vector>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int min = matrix[0][0]; // the minimum number
        int max = matrix[m-1][n-1]+1; // the maximum number+1
        while (min+1 < max) {
            int mid = min + (max - min) / 2;
            // count how many cells are smaller than mid
            int count = 0;
            for (int i = 0; i < m; ++i) {
                int pos = lower_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                count += pos;
            }
            if (count < k) {
                min = mid;
            } else {
                max = mid;
            }
        }
        return min;
    }
};

// Solution
// Binary search through the matrix