// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

// Example:
// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.

#include <iostream> 
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int dp[n];
        memset(dp, 0, n * sizeof(int));
        dp[0] = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = max(nums[i] + dp[i - 1], nums[i]);
            if (dp[i] > ans) ans = dp[i];
        }
        return ans;
    }
};

// Solution
// dp[i] := the max sum of subarray ending with nums[i]
// dp[i] = max(nums[i] + dp[i - 1], nums[i])
// ans = max{dp[i]}