// Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

#include <vector> 
using namespace std; 

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        int dp[n][n];
        for (int diff = 0; diff < n; ++diff) {
            for (int i = 0; i + diff < n; ++i) {
                int j = i + diff;
                if (isIn(A, B, i, j)) dp[i][j] = diff + 1; 
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
    bool isIn(vector<int>& A, vector<int>& B, int i, int j) {
        int pa = 0;
        for (; pa < A.size() - j + i; pa++) {
            if (A[pa] == B[i]) {
                bool flag = true;
                for (int k = 0; i + k <= j; ++k) {
                    if (A[pa + k] != B[i + k]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) return true;
            }
        }
        return false;
    }
};