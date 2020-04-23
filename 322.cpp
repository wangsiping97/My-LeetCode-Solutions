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
    vector<int> tempsol;
    int ans;
    void dfs(int index, vector<int>& coins, int amount) {
        int n = coins.size();
        if (tempsol.size() >= ans || index > n) return; 
        if (amount == 0) {
            ans = ans < tempsol.size() ? ans : tempsol.size();
            return;
        }
        for (int _ = index; _ < n; ++_) {
            int t = amount / coins[_];
            if (amount % coins[_] == 0) {
                ans = ans < tempsol.size() + t ? ans : tempsol.size() + t;
                return;
            }
            if (tempsol.size() + t >= ans) return;
            for (int i = t; i > 0; --i) {
                for (int j = 0; j < i; ++j) tempsol.push_back(coins[_]);
                dfs(_ + 1, coins, amount - i * coins[_]);
                for (int j = 0; j < i; ++j) tempsol.pop_back();
            }
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        ans = amount + 1;
        sort(coins.begin(), coins.end(), greater<int>());
        dfs(0, coins, amount);
        if (ans == amount + 1) return -1;
        return ans;
    }
};