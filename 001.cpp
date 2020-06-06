// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Example:

// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

#include <iostream> 
#include <vector>
#include <unordered_map> 
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, vector<int> > map;
        for (int i = 0; i < nums.size(); ++i) {
            map[nums[i]].push_back(i);
            unordered_map<int, vector<int > >::iterator iter = map.find(target - nums[i]);
            if (iter != map.end()) {
                if (iter->second.size() == 2) return iter->second;
                if (iter->second[0] == i) continue;
                ans.push_back(iter->second[0]);
                ans.push_back(i);
                return ans;
            }
        }
        return ans;
    }
};

// Solution
// hash table