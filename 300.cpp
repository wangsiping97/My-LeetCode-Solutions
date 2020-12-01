// Given an integer array nums, return the length of the longest strictly increasing subsequence.
// A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

#include <vector>
using namespace std; 

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int ans = 1;
        int dp[n];
        memset(dp, 0, n * sizeof(int));
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            int max = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (max < dp[j]) max = dp[j];
                }
            }
            dp[i] = max + 1;
            if (ans < dp[i]) ans = dp[i];
        }
        return ans;
    }
};

// Solution
// 1-dimension dp
// f(n) := length of the longest strictly increasing subsequence **ending with nums[i]**
// Solution := max{f(i)}
// Relationship: f(n) = max{f(j), nums[j] < nums[i], j < i} + 1
// Complexity: O(n^2)