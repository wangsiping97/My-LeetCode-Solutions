// Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

#include <vector> 
using namespace std; 

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return 0;
        long long dp[target + 1];
        memset(dp, 0, (target + 1) * sizeof(long long));
        dp[0] = 1;
        for (int j = 0; j < target + 1; ++j) {
            for (int i = 0; i < n; ++i) {
                if (j >= nums[i]) {
                    if (dp[j] > INT_MAX) continue;
                    dp[j] += dp[j - nums[i]];
                }
            }
        }
        return dp[target];
    }
};

// Solution
// dp[i][j] := num of combinations of the first i elements with amount = j
// dp[i][j] = dp[i][j - nums[i]] + dp[i - 1][j]
// ans = dp[n - 1][target]