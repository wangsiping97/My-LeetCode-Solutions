// Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Your goal is to reach the last index in the minimum number of jumps.
// You can assume that you can always reach the last index.

#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int l = nums.size();
        if (l <= 1) return 0;
        int f[l];
        memset(f, 0, l * sizeof(int));
        for (int i = l - 2; i >= 0; --i) {
            f[i] = INT16_MAX;
            for (int j = 1; j <= nums[i] && i + j < l; ++j) {
                f[i] = min(f[i + j] + 1, f[i]);
            }
        }
        return f[0];
    }
};

// Solution
// Dynamic programming: 
// f(n) := the minimum number of jumps to the last position from the nth position
// answer = f(0)
// transition func: f(n) = min{f(n + i) + 1, for i in (1, nums[n])}