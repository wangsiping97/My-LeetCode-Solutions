// Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

#include <vector> 
using namespace std; 

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        int dp[m][n];
        int res = 0;
        // dp[i][j]: maximum length of subarray in A[0:i] and B[0:j] 
        // and **the subarray ends with A[i] and B[j]**
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) dp[i][j] = A[i] == B[j] ? 1 : 0;
                else if (A[i] != B[j]) dp[i][j] = 0;
                else dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > res) res = dp[i][j];
            }
        }
        return res;
    }
};