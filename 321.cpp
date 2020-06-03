// Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits.
// Note: You should try to optimize your time and space complexity.

#include <iostream> 
#include <vector> 
using namespace std; 

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;
        // dp[i]: the maximum number, i from nums1 and (k-i) from nums2
        int min = k - nums2.size();
        int i = 0 > min ? 0 : min;
        for (; i <= nums1.size(); ++i) {
            vector<int> ans1 = helper(nums1, i);
            vector<int> ans2 = helper(nums2, k - i);
            vector<int> temp = merge(ans1, ans2);
            if (ans.empty()) ans = temp;
            else {
                for (int j = 0; j < k; ++j) {
                    if (ans[j] > temp[j]) break;
                    if (ans[j] < temp[j]) {
                        ans = temp;
                        break;
                    }
                }
            }
        }
        return ans;
    }
    vector<int> helper(vector<int>& nums, int n) {
        vector<int> ans;
        int i;
        for (i = 0; i < n; ++i) {
            ans.push_back(nums[i]);
        }
        for (; i < nums.size(); ++i) {
            vector<int> temp = ans;
            ans.clear();
            temp.push_back(nums[i]);
            bool flag = false;
            for (int j = 0; j <= n; ++j) {
                if (!flag && j < n && temp[j] < temp[j + 1]) {
                    flag = true;
                    continue;
                }
                if (j == n && flag == false) continue;
                ans.push_back(temp[j]);
            }
        }
        return ans;
    }
    vector<int> merge(vector<int>& ans1, vector<int>& ans2) {
        vector<int> ans;
        int n = ans1.size(), m = ans2.size();
        if (n == 0) return ans2;
        if (m == 0) return ans1;
        int i = 0, j = 0;
        while (i != n && j != m) {
            if (larger(ans1, ans2, i, j)) {
                ans.push_back(ans1[i]);
                i++;
            }
            else {
                ans.push_back(ans2[j]);
                j++;
            }
        }
        while (i != n) {
            ans.push_back(ans1[i]);
            i++;
        }
        while (j != m) {
            ans.push_back(ans2[j]);
            j++;
        }
        return ans;
    }
    
    bool larger(vector<int>& ans1, vector<int>& ans2, int i, int j) {
        int k = 0;
        for (; k + i < ans1.size() && k + j < ans2.size(); ++k) {
            if (ans1[k + i] > ans2[k + j]) return true; 
            if (ans1[k + i] < ans2[k + j]) return false;
        }
        if (k + i == ans1.size()) return false;
        return true;
    }

};