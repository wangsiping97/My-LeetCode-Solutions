// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
// You may assume that the array is non-empty and the majority element always exist in the array.

#include <vector> 
#include <map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int counter = 1;
        for (int i = 1; i < n; ++i) {
            if (counter > 0 && nums[i] != ans) {
                counter--;
                if (counter == 0) {
                    ans = nums[i];
                    counter = 1;
                }
            } else if (nums[i] == ans) {
                counter++;
            }
        }
        return ans;
    }
};

// Solution
// voting method