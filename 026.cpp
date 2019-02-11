// Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

// Example 1:
// Given nums = [1,1,2],
// Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

// Example 2:
// Given nums = [0,0,1,1,1,2,2,3,3,4],
// Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

// It doesn't matter what values are set beyond the returned length.

#include <iostream> 
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i < nums.size(); nums[i] != nums[i - 1] ? nums[++count] = nums[i], i++: i++);
        return nums.size() <= 1 ? nums.size() : count + 1;
    }
};

int main() {
    Solution s;
    int nums[10] = {0,0,1,1,1,2,2,3,3,4};
    vector<int> v(nums, nums + 10);
    int ans = s.removeDuplicates(v);
    cout << ans << endl;
    for (int i = 0; i < ans; cout << v[i] << " ", i++);
    return 0;
}