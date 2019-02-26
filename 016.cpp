// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

// Example:
// Given array nums = [-1, 2, 1, -4], and target = 1.
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

#include <iostream> 
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        int l = nums.size();
        float uni_tar = (float)target / 3;
        int i = 0;
        while (i < l && nums[i] < uni_tar) 
            i++;
        if (i == l) return ans = nums[l - 1] + nums[l - 2] + nums[l - 3];
        for(int j = 0; j <= i; j++) {
            int s = l - 1;
            for(int k = j + 1; k < s; k++) {
                int temp = nums[j] + nums[k];
                while (s > k + 1 && nums[s] + temp > target)
                    s--;
                if (s < l - 1 && temp + nums[s + 1] - target < abs(ans - target)) ans = temp + nums[s + 1];
                if (abs(temp + nums[s] - target) < abs(ans - target)) ans = temp + nums[s];
                while (k + 1 < l && nums[k + 1] == nums[k]) 
                    k++;
            }
            while ( j + 1 < l && nums[j + 1] == nums[j]) 
                j++;
        }
        return ans;
    }
};