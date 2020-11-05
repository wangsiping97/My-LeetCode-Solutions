// Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.
// Do not allocate extra space for another array; you must do this by modifying the input array in-place with O(1) extra memory.
// Clarification:
// Confused why the returned value is an integer, but your answer is an array?
// Note that the input array is passed in by reference, which means a modification to the input array will be known to the caller.

#include <vector> 
using namespace std; 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int tmp = 10001;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1]) {
                count++;
                if (count > 2) {
                    remove(nums, i);
                    n--;
                    i--;
                }
            }
            else count = 1;
        }
        return nums.size();
    }
    void remove(vector<int>& nums, int idx) {
        int n = nums.size();
        for (int i = idx; i < n - 1; ++i) {
            nums[i] = nums[i + 1];
        }
        nums.pop_back();
    }
};