// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

#include <iostream> 
using namespace std; 

class Solution {
public:
    int numSquares(int n) {
        int dp[n + 1];
        for (int i = 1; i < n + 1; ++i) {
            dp[i] = INT_MAX;
            for (int j = 1; j * j <= i; ++j) {
                if (j * j == i) dp[i] = 1;
                else dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};