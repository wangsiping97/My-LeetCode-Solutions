// You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

#include <vector> 
using namespace std; 

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (coins.empty()) return amount == 0;
        sort(coins.begin(), coins.end());
        int n = coins.size();
        int dp[amount + 1][n];
        for (int i = 0; i < n; ++i) {
            for (int s = 0; s <= amount; ++s) {
                if (s == 0) dp[s][i] = 1;
                else if (i == 0) dp[s][i] = s % coins[i] == 0 ? 1 : 0;
                else {
                    dp[s][i] = 0;
                    int temp = s;
                    while (temp >= 0) {
                        dp[s][i] += dp[temp][i - 1];
                        temp -= coins[i];
                    }
                }
            }
        }
        return dp[amount][n - 1];
    }
};