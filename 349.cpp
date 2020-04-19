// Given two arrays, write a function to compute their intersection.

// Example 1:
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]

// Example 2:
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]

// Note:
// Each element in the result must be unique.
// The result can be in any order.

#include <vector> 
#include <unordered_map>
using namespace std; 

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> ans;
        unordered_map<int, int> hashmap;
        for (int i = 0; i < m; ++i) {
            hashmap[nums1[i]] = 1;
        }
        for (int j = 0; j < n; ++j) {
            if (hashmap[nums2[j]] == 1) {
                hashmap[nums2[j]] = -1;
                ans.push_back(nums2[j]);
            }
        }
        return ans;
    }
};