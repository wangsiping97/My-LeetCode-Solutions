// You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

// If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

// Return the maximum coins you can collect by bursting the balloons wisely.

#include <iostream> 
#include <vector> 

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.emplace_back(1);
        int n = nums.size();
        int dp[n][n]; // dp[i][j] := max coins you can earn from nums[i:j], without bursting nums[i] & nums[j]
        memset(dp, 0, sizeof(dp));
        for (int diff = 2; diff < n; ++diff) {
            for (int i = 0; i + diff < n; ++i) {
                int j = i + diff;
                int res = 0;
                for (int k = i+1; k < j; ++k) {
                    int tmp = dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j];
                    if (tmp > res) res = tmp;
                }
                dp[i][j] = res;
            }
        }
        return dp[0][n-1];
    }
};

