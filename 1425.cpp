// Given an integer array nums and an integer k, return the maximum sum of a
// non-empty subsequence of that array such that for every two consecutive
// integers in the subsequence, nums[i] and nums[j], where i < j, the condition
// j - i <= k is satisfied. A subsequence of an array is obtained by deleting
// some number of elements (can be zero) from the array, leaving the remaining
// elements in their original order.

#include <deque>
#include <vector>
using namespace std;

class Solution {
 public:
  int constrainedSubsetSum(vector<int>& nums, int k) {
    int n = nums.size();
    int cur = nums[0];
    int ans = cur;
    deque<pair<int, int>> q;
    q.push_back(pair<int, int>(0, cur));
    for (int i = 1; i < n; ++i) {
      if (i > k) {
        int top_idx = q.front().first;
        if (top_idx < i - k) {
          q.pop_front();
        }
      }
      int max = q.front().second;
      if (max < 0) max = 0;
      cur = max + nums[i];
      if (cur > ans) ans = cur;
      // push dp[i]
      while (!q.empty()) {
        int back = q.back().second;
        if (back <= cur) {
          q.pop_back();
        } else {
          break;
        }
      }
      q.push_back(pair<int, int>(i, cur));
    }
    return ans;
  }
};

// Solution
// dp[i] := max sum of sub array ends with nums[i]
// ans = max{dp[0], dp[1], ... , dp[n-1]}
// dp[i] = nums[i] + max{0, dp[i-1], dp[i-2], ..., dp[i-k]}, dp[0] = nums[0]
// we are maintaining the largest value in a sliding window (size = k) in the dp
// array monotonic queue should help us