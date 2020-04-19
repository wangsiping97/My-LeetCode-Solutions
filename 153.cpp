// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
// Find the minimum element.
// You may assume no duplicate exists in the array.

#include <vector> 
using namespace std; 

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n - 1; 
        int mid;
        while (start <= end) {
            // 1. nums[start] is min
            if (nums[start] <= nums[end]) return nums[start];
            mid = start + (end - start) / 2;
            // 2. nums[mid] is min
            if (nums[mid] >= nums[start]) start = mid + 1;
            else if (nums[mid] < nums[end]) end = mid;
            // 3. nums[end] is min
            else return nums[end];
        }
        return nums[mid];
    }
};