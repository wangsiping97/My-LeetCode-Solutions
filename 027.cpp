// Given an array nums and a value val, remove all instances of that value in-place and return the new length.
// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
// The order of elements can be changed. It doesn't matter what you leave beyond the new length.

// Example 1:
// Given nums = [3,2,2,3], val = 3,
// Your function should return length = 2, with the first two elements of nums being 2.

// Example 2:
// Given nums = [0,1,2,2,3,0,4,2], val = 2,
// Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.
// Note that the order of those five elements can be arbitrary.

// It doesn't matter what values are set beyond the returned length.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for (int i = nums.size() - 1; i >= 0; nums[i] == val ? count++, nums[i] = nums[nums.size() - count], nums[nums.size() - count] = val, i-- : i--) ;
        return nums.size() - count;
    }
};

int main() {
    Solution s;
    int nums[8] = {0,1,2,2,3,0,4,2};
    vector<int> v(nums, nums + 8);
    int ans = s.removeElement(v, 2);
    cout << ans << endl;
    for (int i = 0; i < ans; cout << v[i] << " ", i++);
    return 0;
}