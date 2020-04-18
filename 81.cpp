// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
// You are given a target value to search. If found in the array return true, otherwise return false.

#include <vector> 
using namespace std; 

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size(); 
        if (n == 0) return false;
        int start = 0, end = n - 1;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                start = i + 1;
                end = i;
                break;
            }
        }
        if (start == 0) return target == nums[start];
        if (target >= nums[0]) start = 0;
        else end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target == nums[mid]) return true;
            if (target > nums[mid]) start = mid + 1;
            else end = mid - 1;
        }
        return false;
    }
};