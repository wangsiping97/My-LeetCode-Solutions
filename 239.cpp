// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
// Return the max sliding window.

#include <vector> 
#include <deque> 
using namespace std; 

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        if (n == 0) return ans;
        if (n == 1 || k == 1) return nums;
        deque<int> tmp; // 单调栈
        tmp.push_back(0);
        for(int i = 1; i < n; ++i) {
            if (i >= k && tmp[0] <= i - k) tmp.pop_front();
            if (nums[tmp.back()] > nums[i]) {
                tmp.push_back(i);
            } else {
                while (!tmp.empty() && nums[tmp.back()] <= nums[i]) tmp.pop_back();
                tmp.push_back(i);
            }
            if (i >= k - 1) ans.push_back(nums[tmp[0]]);
        }
        return ans;
    }
};

// Solution
// 单调减栈