// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

#include <vector> 
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p1 = -1; // the position of the first 0 in the array
        int p2 = -1; // the position of the first non-zero element after p1
        int n = nums.size();
        // find p1 and p2
        for (int i = 0; i < n; ++i) {
            if (p1 == -1 && nums[i] == 0) {
                p1 = i;
            } 
            if (p1 != -1 && p2 == -1 && nums[i] != 0) {
                p2 = i;
                break;
            }
        }
        // corner case
        if (p1 == -1 || p2 == -1) return;
        // move
        while (p2 < n) {
            nums[p1] = nums[p2];
            nums[p2] = 0;
            // find new p1
            while (p1 < n && nums[p1] != 0) p1++; // p1 <= p2
            while (p2 < n && nums[p2] == 0) p2++;
        }
    }
};