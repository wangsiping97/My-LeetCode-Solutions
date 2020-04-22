// Given a non-empty array of integers, every element appears twice except for one. Find that single one.

// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

#include <vector> 
using namespace std; 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans ^= nums[i];
        }
        return ans;
    }
};

// Solution
// Bit-manipulation - 位运算