// Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

// 0 <= i, j, k, l < n
// nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

#include <vector> 
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int, int> map12;
        unordered_map<int, int> map34;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                map12[nums1[i] + nums2[j]]++;
                map34[nums3[i] + nums4[j]]++;
            }
        }
        int ans = 0;
        for (auto pair : map12) {
            int sum = pair.first;
            ans += pair.second * map34[-sum];
        }
        return ans;
    }
};