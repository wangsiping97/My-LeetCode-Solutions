// Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

// Note:
// Each of the array element will not exceed 100.
// The array size will not exceed 200.

#include <vector> 
using namespace std; 

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return true;
        int sum = 0;
        for (int val : nums) sum += val; 
        if (sum % 2 == 1) return false;
        bool dp[sum + 1];
        memset(dp, false, (sum + 1) * sizeof(bool));
        dp[0] = true;
        dp[nums[0]] = true;
        for (int i = 1; i < n; ++i) {
            for (int j = sum / 2; j >= nums[i]; --j) {
                dp[j] = dp[j] | dp[j - nums[i]];
                if (j == sum / 2 && dp[sum / 2] == true) return true;
            }
        }
        return false;
    }
};

// Solution
// dp[i][j] := having considered first i elements in nums, with an amount of j
// dp[i][j] := 0 if j cannot be reached, 1 otherwise
// dp[i][j] = dp[i - 1][j - nums[i]] | dp[i - 1][j]
// ans = dp[nums.size() - 1][sum / 2]
// trick: scan j from large to small