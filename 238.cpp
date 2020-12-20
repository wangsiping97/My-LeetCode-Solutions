// Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

// Example:
// Input:  [1,2,3,4]
// Output: [24,12,8,6]
// Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

// Note: Please solve it without division and in O(n).

// Follow up:
// Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

#include <vector> 
using namespace std; 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> left(n);
        vector<int> right(n);
        for (int i = 0; i < n; ++i) {
            if (i == 0) left[0] = 1;
            else {
                left[i] = left[i - 1] * nums[i - 1];
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) right[n - 1] = 1;
            else {
                right[i] = right[i + 1] * nums[i + 1];
            }
        }
        for (int i = 0; i < n; ++i) {
            ans.push_back(left[i] * right[i]);
        }
        return ans;
    }
};

// Solution
// left[i] := product of nums[0:i-1]
// right[i] := product of nums[i + 1:-1]