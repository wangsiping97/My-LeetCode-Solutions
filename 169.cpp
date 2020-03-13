// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
// You may assume that the array is non-empty and the majority element always exist in the array.

#include <vector> 
#include <map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        int l = nums.size();
        for (int i = 0; i < l; ++i) {
            m[nums[i]]++;
            if (m[nums[i]] > l / 2) return nums[i];
        }
        return -1;
    }
};

// Solution
// (Hash) map