// Search for a target number in a bitonic array, return the index of the target number if found in the array, or return -1. 

#include <iostream> 
#include <vector> 
using namespace std; 

class Solution {
public: 
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
    int binarySearch(vector<int>& nums, int target, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            if (target == nums[mid]) return mid;
            if (target > nums[mid]) {
                if (nums[mid] < nums[mid + 1]) return binarySearch(nums, target, mid + 1, right);
                else return binarySearch(nums, target, left, mid - 1);
            }
            else {
                int result = binarySearch(nums, target, left, mid - 1);
                if (result == -1) return binarySearch(nums, target, mid + 1, right);
                return result;
            }
        }
        return -1;
    }
};

int main() {
    Solution s; 
    int arr[8] = {1, 4, 7, 11, 6, 2, -3, -8};
    vector<int> nums; 
    for (int i = 0; i < 8; ++i) {
        nums.push_back(arr[i]);
    }
    cout << s.search(nums, 2) << endl;
}