// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
// You are given a target value to search. If found in the array return its index, otherwise return -1.
// You may assume no duplicate exists in the array.
// Your algorithm's runtime complexity must be in the order of O(log n).

// Example 1:
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Example 2:
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

#include <iostream> 
#include <vector> 
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = nums.size();
        if (l == 0) return -1;
        int mid, start = 0, end = l - 1;
        while (start < end) {
            mid = (start + end) / 2;
            if (nums[mid] > nums[start]) start = mid;
            else if (nums[mid] < nums[start]) end = mid - 1; 
            else start = mid + 1;
        }
        if (target > nums[0]) end = start, start = 0;
        else if (target < nums[0]) end = l - 1;
        else return 0;
        while (start <= end) {
            mid = (start + end) / 2;
            if (nums[mid] < target) start = mid + 1;
            else if (nums[mid] > target) end = mid - 1;
            else return mid;
        }
        return -1;
    }
};