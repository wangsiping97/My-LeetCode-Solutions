// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

#include <vector> 
using namespace std; 

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int dp_max[n], dp_min[n];
        memset(dp_max, 0, n * sizeof(int));
        memset(dp_min, 0, n * sizeof(int));
        dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > 0) {
                dp_max[i] = max(dp_max[i - 1] * nums[i], nums[i]);
                dp_min[i] = min(dp_min[i - 1] * nums[i], nums[i]);
            }
            else {
                dp_max[i] = max(dp_min[i - 1] * nums[i], nums[i]);
                dp_min[i] = min(dp_max[i - 1] * nums[i], nums[i]);
            }
            if (ans < dp_max[i]) ans = dp_max[i];
        }
        return ans; 
    }
};