// Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

#include <vector> 
#include <iostream> 
using namespace std; 

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.begin() + k, greater<int>());
        for (int i = k; i < nums.size(); ++i) {
            if (nums[i] > nums[0]) {
                pop_heap(nums.begin(), nums.begin() + k, greater<int>());
                swap(nums[i], nums[k - 1]);
                push_heap(nums.begin(), nums.begin() + k, greater<int>());
            }
        }
        return nums[0];
    }
};