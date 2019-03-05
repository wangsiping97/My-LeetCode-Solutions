// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
// Note:
// The solution set must not contain duplicate quadruplets.

// Example:
// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]

#include <iostream> 
#include <vector>
using namespace std;

class Solution {
public:
    vector< vector<int> > fourSum(vector<int>& nums, int target) {
        vector< vector<int> > ans;
        vector<int> v;
        int l = nums.size();
        if (l < 4) return ans;
        sort(nums.begin(), nums.end());
        float t = target / 4;
        int i = 0;
        while (i < l && nums[i] < t) i++;
        if (i == l) return ans;
        for (int j = 0; j <= i; j++) {
            float threeTar = (target - nums[j]) / 3;
            int ii = j + 1;
            while (ii < l && nums[ii] < threeTar) ii++;
            for (int k = j + 1; k <= ii; k++) {
                int s = l - 1;
                for (int m = k + 1; m < s; m++) {
                    int temp = nums[j] + nums[k] + nums[m];
                    while (s > m + 1 && nums[s] > target - temp) s--;
                    if (nums[s] == target - temp) {
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        v.push_back(nums[m]);
                        v.push_back(nums[s]);
                        ans.push_back(v);
                        v.clear();
                    }
                    while (m + 1 < l && nums[m + 1] == nums[m]) m++;
                }
                while (k + 1 < l && nums[k + 1] == nums[k]) k++;
            }
            while (j + 1 < l && nums[j + 1] == nums[j]) j++;
        }
        return ans;
    }
};