// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

// The replacement must be in-place and use only constant extra memory.

// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

#include <iostream> 
#include <vector> 
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int l = nums.size();
        int i = l - 1, j = l - 1;
        while (i > 0 && nums[i - 1] >= nums[i])
            i--;
        if (i == 0) {
            sort(nums.begin(), nums.end()); 
            return;
        }
        while (nums[j] <= nums[i - 1])
            j--;
        swap(nums[i - 1], nums[j]);
        vector<int>::iterator iter = nums.begin();
        for (int k = 0; k < i; k++) {
            iter++;
        } 
        sort(iter, nums.end());
    }
};