// A peak element is an element that is greater than its neighbors.
// Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.
// The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
// You may imagine that nums[-1] = nums[n] = -∞.

#include <vector> 
using namespace std; 

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int start = 0, end = n - 1;
        int mid;
        while (start < end) {
            mid = start + (end - start) / 2;
            if (nums[mid] > nums[mid + 1]) {
                end = mid;
            } 
            else {
                start = mid + 1;
            }
        }
        return start;
    }
};

// Solution
// 我们取中间mid位置，如果该点满足要求，就直接找到了这个索引，就是mid。否则，我们二分搜索mid索引左边和右边较高的那个点的那一边，我们就一定能找到一个顶峰，这是为什么呢？
// 我们将索引分成2段，[left, mid - 1]，[mid + 1, right]，如果mid不满足要求，那么说明mid - 1和mid + 1这两个位置必然有一个位置的值大于mid位置的值。而mid - 1和mid + 1中的较大者必然是大于mid位置的值的。假设mid - 1位置的值大于等于mid + 1位置的值，那么我们再[left, mid - 1]中一定能找到一个顶峰。