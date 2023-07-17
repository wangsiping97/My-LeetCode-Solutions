// Find the kth largest element in an unsorted array. Note that it is the kth
// largest element in the sorted order, not the kth distinct element.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 1) return nums[0];
    int pivot = nums[0];
    vector<int> left;
    vector<int> right;
    for (int val : nums) {
      if (val > pivot) {
        left.push_back(val);
      } else if (val < pivot) {
        right.push_back(val);
      }
    }
    int n_left = left.size();
    int n_right = right.size();
    int n_mid = n - n_left - n_right;
    if (n_left >= k) {
      return findKthLargest(left, k);
    }
    if (n_left + n_mid >= k) {
      return pivot;
    }
    return findKthLargest(right, n_right - (n - k));
  }
};

// Solution
// Similar to fastsort, O(N)