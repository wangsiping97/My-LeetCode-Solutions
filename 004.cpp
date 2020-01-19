// There are two sorted arrays nums1 and nums2 of size m and n respectively.

// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

// You may assume nums1 and nums2 cannot be both empty.

// Example 1:

// nums1 = [1, 3]
// nums2 = [2]

// The median is 2.0
// Example 2:

// nums1 = [1, 2]
// nums2 = [3, 4]

// The median is (2 + 3)/2 = 2.5

#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int mid, flag;
        mid = (m + n) / 2;
        if ((m + n) % 2 == 0) flag = 1;
        else flag = 0;
        int count = 0;
        int count2 = 0;
        while (count2 < n && count <= (m + n) / 2) {
            if (count >= nums1.size()) {
                nums1.push_back(nums2[count2]);
                count2++;
            }
            else if (nums2[count2] < nums1[count]) {
                nums1.insert(nums1.begin() + count, nums2[count2]);
                count2++;
            }
            count++;
        }
        if (flag == 1) return (double)(nums1[mid - 1] + nums1[mid])/2;
        else return nums1[mid];
    }
};