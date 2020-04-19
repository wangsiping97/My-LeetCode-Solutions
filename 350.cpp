// Given two arrays, write a function to compute their intersection.

// Example 1:
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]

// Example 2:
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]

// Note:
// Each element in the result should appear as many times as it shows in both arrays.
// The result can be in any order.

// Follow up:
// What if the given array is already sorted? How would you optimize your algorithm?
// What if nums1's size is small compared to nums2's size? Which algorithm is better?
// What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

#include <unordered_map> 
#include <vector> 
using namespace std; 

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> ans;
        unordered_map<int, int> hashmap;
        for (int i = 0; i < m; ++i) {
            hashmap[nums1[i]]++;
        }
        for (int j = 0; j < n; ++j) {
            if (hashmap[nums2[j]] > 0) {
                hashmap[nums2[j]]--;
                ans.push_back(nums2[j]);
            }
        }
        return ans;
    }
};