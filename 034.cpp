// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

#include <vector> 
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int left, int right) {
        if (left > right) return -1;
        if (left == right && nums[left] != target) return -1;
        int med = (left + right) / 2;
        if (nums[med] < target) return binarySearch(nums, target, med + 1, right);
        if (nums[med] > target) return binarySearch(nums, target, left, med - 1);
        else return med;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        int t = binarySearch(nums, target, 0, n - 1);
        if (t == -1) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int i = t, j = t;
        while (i >= 0 && nums[i] == target) {
            i--;
        }
        while (j < n && nums[j] == target) {
            j++;
        }
        ans.push_back(i + 1);
        ans.push_back(j - 1);
        return ans;
    }
};