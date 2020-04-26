// Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

#include <vector> 
#include <cstdlib> 
using namespace std; 

class Solution {
public:
    int sum;
    bool flag;
    void dfs(bool* used, vector<int>& nums, int target, int k) {
        if (flag == true) return;
        if (k == 0) {
            flag = true;
            return;
        };
        if (target == 0) {
            return dfs(used, nums, sum, k - 1);
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] == false && nums[i] <= target) {
                used[i] = true;
                dfs(used, nums, target - nums[i], k);
                if (flag == true) return;
                used[i] = false;
            }
        }
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        flag = false;
        int n = nums.size();
        if (n < k) return false;
        sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }
        if (sum % k != 0) return false;
        sum /= k;

        bool* used = (bool*)malloc(n * sizeof(bool));
        memset(used, false, n * sizeof(bool));

        dfs(used, nums, sum, k);
        return flag;
    }
};