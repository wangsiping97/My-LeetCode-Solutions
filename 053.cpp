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
        int max = 0, iter = 0, l = nums.size();
        int temp = 0;
        for (int i = 0; i < l; i++) {
            temp += nums[i];
            if (temp > max) {
                max = temp;
                iter++;
            }
            else if (temp < 0) {
                temp = 0;
            }
        }
        if (iter == 0) {
            sort(nums.begin(), nums.end());
            return nums[l - 1];
        }
        return max;
    }
};