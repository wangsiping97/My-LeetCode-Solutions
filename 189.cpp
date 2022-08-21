// Given an array, rotate the array to the right by k steps, where k is non-negative.

#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> processed;
    void rotate(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); ++i)
            processed.emplace_back(false);
        for (int i = 0; i < nums.size(); ++i) 
            helper(nums, i, k);
    }
    void helper(vector<int>& nums, int pos, int k) {
        if (processed[pos])
            return;
        processed[pos] = true;
        int n = nums.size();
        int new_pos = pos+k;
        while (new_pos >= n) {
            new_pos -= n;
        }
        int value = nums[pos];
        helper(nums, new_pos, k);
        nums[new_pos] = value;
    }
};