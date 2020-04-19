// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
// Find the minimum element.
// The array may contain duplicates.

#include <vector> 
#include <cstdlib>
using namespace std; 

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int start = 0, end = n - 1, mid; 
        while (start <= end) {
            while (end > start && nums[start] == nums[end]) end--;
            // 1. nums[start] is min
            if (nums[start] <= nums[end]) return nums[start];
            // 2. nums[mid] is min
            mid = start + (end - start) / 2; 
            while (mid < end && nums[mid] == nums[start]) mid++; 
            if (mid == end) return nums[end];
            if (nums[mid] > nums[start]) start = mid + 1;
            else {
                while (mid > start && nums[mid] == nums[end]) mid--;
                if (nums[mid] < nums[end]) end = mid;
                else return nums[end];
            }
        }
        exit(0);
    }
};