// Given an integer array nums, return the number of longest increasing subsequences.
// Notice that the sequence has to be strictly increasing.

#include <vector> 
using namespace std; 

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int dp[n];
        int count[n]; // number of longest increasing subsequences ending with nums[i]
        memset(dp, 0, n * sizeof(int));
        memset(count, 0, n * sizeof(int));
        dp[0] = 1;
        count[0] = 1;
        int ans = 1; // smallest possible answer
        int max_length = 1;
        for (int i = 1; i < n; ++i) {
            int tmp = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (tmp < dp[j]) {
                        count[i] = count[j];
                        tmp = dp[j];
                    }
                    else if (tmp == dp[j]) count[i] += count[j];
                }
            }
            if (tmp == 0) count[i]++;
            dp[i] = tmp + 1;
            if (max_length < dp[i]) {
                max_length = dp[i];
                ans = count[i];
            }
            else if (max_length == dp[i]) ans += count[i];
        }
        return ans;
    }
};

// Solution
// Similiar to 300.cpp 
// Use count[n] to store the number of increasing subsequences ending with nums[i]