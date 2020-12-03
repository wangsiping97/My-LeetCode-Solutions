// You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// Example 1:
// Input: coins = [1, 2, 5], amount = 11
// Output: 3 
// Explanation: 11 = 5 + 5 + 1

// Example 2:
// Input: coins = [2], amount = 3
// Output: -1

// Note:
// You may assume that you have an infinite number of each kind of coin.

#include <vector> 
#include <iostream> 
using namespace std; 

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        int n = coins.size();
        if (n == 0) return -1;
        if (amount == 0) return 0;
        long long max = amount / coins[n - 1];
        long long dp[n][amount + 1];
        for (long long i = 0; i < n; ++i) {
            for (long long j = 0; j <= amount; ++j) dp[i][j] = max + 1;
            if (coins[i] <= amount)
                dp[i][coins[i]] = 1;
        }
        for (long long i = 0; i < n; ++i) {
            for (long long j = (long long)coins[i] + 1; j <= amount; ++j) {
                if (i == 0) dp[i][j] = dp[i][j - coins[i]] + 1;
                else dp[i][j] = min(dp[i][j - coins[i]] + 1, dp[i - 1][j]);
            }
        }
        if (dp[n - 1][amount] > max) return -1;
        return dp[n - 1][amount];
    }
};

// Solution
// dp[i][j] := the smallest number of coins before coins[i] with amount = j
// dp[i][j] = min{dp[i][j - coins[i]] + 1, dp[i - 1][j]}