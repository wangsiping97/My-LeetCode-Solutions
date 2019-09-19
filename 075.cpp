// Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.
// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
// Note: You are not suppose to use the library's sort function for this problem.

#include <vector> 
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return;
        int a = 0, b = n - 1;
        for (int i = a; i <= b; i++) {
            if (nums[i] == 0) swap(nums[i], nums[a++]);
            if (nums[i] == 2) swap(nums[i--], nums[b--]);
        }
    }
};