// Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

// Note:
// Each of the array element will not exceed 100.
// The array size will not exceed 200.

#include <vector> 
using namespace std; 

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) sum += nums[i];
        if (sum % 2 == 1) return false; 
        sum /= 2;
        bool dp[n][sum + 1];
        for (int i = 0; i < n; ++i) {
            if (nums[i] > sum) return false;
            for (int j = 0; j <= sum; ++j) {
                if (i == 0) dp[i][j] = nums[i] == j ? true : false;
                else if (j < nums[i]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j - nums[i]] || dp[i - 1][j];
            }
        }
        return dp[n - 1][sum];
    }
};