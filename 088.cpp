// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
// Note:
// The number of elements initialized in nums1 and nums2 are m and n respectively.
// You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.

#include <vector> 
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        while (j < n) {
            while (i < m && nums1[i + j] <= nums2[j]) {
                i++;
            }
            nums1.insert(nums1.begin() + i + j, nums2[j]);
            j++;
        }
        nums1.resize(m + n);
    }
};

// Solution:
// tow pointers, i and j, meaning the first (i+j) numbers in nums1 and the first j numbers in nums2 have been managed.
