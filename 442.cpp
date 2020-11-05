// Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
// Find all the elements that appear twice in this array.
// Could you do it without extra space and in O(n) runtime?

#include <vector> 
using namespace std; 

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            if (nums[abs(nums[i]) - 1] > 0) ans.push_back(abs(nums[i]));
        }
        return ans;
    }
};