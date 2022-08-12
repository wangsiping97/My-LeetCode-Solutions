// You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

// Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.

// Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.

#include <iostream>
#include <vector> 
using namespace std; 

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int sum[n][n];
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (i == j) sum[i][j] = nums[i];
                else {
                    sum[i][j] = sum[i][j-1] + nums[j];
                }
            }
        }
        int dp[n][n]; // max score player 1 can get with nums[i:j]
        memset(dp, 0, sizeof(dp));
        for (int diff = 0; diff < n; ++diff) {
            for (int i = 0; i + diff < n; ++i) {
                int j = i + diff;
                if (i == j) dp[i][j] = nums[i];
                else {
                    dp[i][j] = max(nums[i] + sum[i+1][j] - dp[i+1][j], nums[j] + sum[i][j-1] - dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1] >= sum[0][n-1] - dp[0][n-1];
    }
};