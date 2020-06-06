// Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

#include <iostream> 
using namespace std; 

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        dp[4] = 4;
        for (int i = 5; i <= n; ++i) {
            dp[i] = 0;
            for (int k = 1; k <= i / 2; ++k) {
                int temp = dp[k] * dp[i - k];
                if (temp > dp[i]) dp[i] = temp;
            }
        }
        return dp[n];
    }
};