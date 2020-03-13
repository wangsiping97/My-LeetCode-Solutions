// Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

// Note:
// Your returned answers (both index1 and index2) are not zero-based.
// You may assume that each input would have exactly one solution and you may not use the same element twice.

#include <vector> 
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& numbers, int start, int tar) {
        int low = start, high = numbers.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (numbers[mid] > tar) high = mid - 1;
            else if (numbers[mid] < tar) low = mid + 1;
            else return mid; 
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int l = numbers.size();
        for (int i = 0; i < l; ++i) {
            if (numbers[l - 1] < target - numbers[i]) continue;
            int j = binarySearch(numbers, i + 1, target - numbers[i]);
            if (j != -1) {
                ans.push_back(i + 1);
                ans.push_back(j + 1);
                break;
            }
        }
        return ans;
    }
};

// Solution
// Binary Search