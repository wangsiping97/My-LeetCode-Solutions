// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

// Note:
// The solution set must not contain duplicate triplets.

// Example:
// Given array nums = [-1, 0, 1, 2, -1, -4],
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

#include <iostream> 
#include <vector> 
using namespace std;

class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        vector< vector<int> > ans;
        vector<int> v;
        int l = nums.size();
        if (l < 3) return ans;
        sort(nums.begin(), nums.end()); 
        int i = 0;
        while (i < l && nums[i] < 0) 
            i++;
        if (i == l) return ans;
        for(int j = 0; j <= i; j++) {
            int s = l - 1;
            for(int k = j + 1; k < s; k++) {
                int temp = nums[j] + nums[k];
                while (s > k + 1 && nums[s] > -temp) 
                    s--;
                if (nums[s] == -temp) {
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    v.push_back(nums[s]);
                    ans.push_back(v);
                    v.clear();
                }
                while (k + 1 < l && nums[k + 1] == nums[k]) 
                    k++;
            }
            while ( j + 1 < l && nums[j + 1] == nums[j]) 
                j++;
        }
        return ans;
    }
};