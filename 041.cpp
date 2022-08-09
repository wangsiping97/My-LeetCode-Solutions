// Given an unsorted integer array nums, return the smallest missing positive integer.
// You must implement an algorithm that runs in O(n) time and uses constant extra space.

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public: 
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 1;
        int tmp;
        int pos = 0;
        while (pos < n && (nums[pos] <= 0 || nums[pos] > n)) {
            pos++;
        }
        if (pos == n) {
            return 1;
        }
        tmp = nums[pos];
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = tmp;
            }
        }
        for (int i = 0; i < n; ++i) {
            int idx = abs(nums[i]) -1;
            if (nums[idx] > 0) {
                nums[idx] = -nums[idx];
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                return i+1;
            }
        }

        return n+1;
    }
};

// Solution
// the answer is in [1, n+1] => we can use index
