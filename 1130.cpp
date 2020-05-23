// Given an array arr of positive integers, consider all binary trees such that:
// Each node has either 0 or 2 children;
// The values of arr correspond to the values of each leaf in an in-order traversal of the tree.  (Recall that a node is a leaf if and only if it has 0 children.)
// The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree respectively.
// Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node.  It is guaranteed this sum fits into a 32-bit integer.

#include <vector> 
#include <cstdlib> 
using namespace std; 

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        int** dp = (int**)malloc(n * sizeof(int*));
        for (int i = 0; i < n; ++i) {
            dp[i] = (int*)malloc(n * sizeof(int));
            memset(dp[i], 0, n * sizeof(int));
        }
        int** max = (int**)malloc(n * sizeof(int*));
        for (int i = 0; i < n; ++i) {
            max[i] = (int*)malloc(n * sizeof(int));
            memset(max[i], 0, n * sizeof(int));
        }

        for (int diff = 0; diff < n; ++diff) {
            for (int start = 0; start + diff < n; ++start) {
                int end = start + diff;
                if (diff == 0) {
                    dp[start][end] = 0;
                    max[start][end] = arr[start];
                    continue;
                }
                max[start][end] = arr[end] > max[start][end - 1] ? arr[end] : max[start][end - 1];
                if (diff == 1) {
                    dp[start][end] = arr[start] * arr[end];
                    continue;
                }
                int min = INT_MAX; 
                for (int k = start; k < end; ++k) {
                    int temp = dp[start][k] + dp[k + 1][end] + max[start][k] * max[k + 1][end];
                    if (min > temp) min = temp;
                }
                dp[start][end] = min;
            }
        }
        return dp[0][n - 1];
    }
};