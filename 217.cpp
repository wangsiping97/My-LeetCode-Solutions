// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int v : nums) {
            map[v]++;
            if (map[v] == 2) {
                return true;
            }
        }
        return false;
    }
};