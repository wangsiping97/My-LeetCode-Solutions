// You are given an array nums of positive integers and a positive integer k.
// A subset of nums is beautiful if it does not contain two integers with an
// absolute difference equal to k. Return the number of non-empty beautiful
// subsets of the array nums. A subset of nums is an array that can be obtained
// by deleting some (possibly none) elements from nums. Two subsets are
// different if and only if the chosen indices to delete are different.

#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int count = 0;
  unordered_set<int> tmp;
  void dfs(vector<int>& nums, int idx, int k) {
    if (idx == nums.size() - 1) {
      count++;
      return;
    }
    for (int i = idx + 1; i < nums.size(); ++i) {
      if (nums[i] - nums[idx] == k) continue;
      if (tmp.find(nums[i] - k) == tmp.end()) {
        if (tmp.find(nums[i]) == tmp.end()) {
          tmp.insert(nums[i]);
          dfs(nums, i, k);
          tmp.erase(nums[i]);
        } else {
          dfs(nums, i, k);
        }
      }
    }
    count++;
  }
  int beautifulSubsets(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      tmp.insert(nums[i]);
      dfs(nums, i, k);
      tmp.erase(nums[i]);
    }
    return count;
  }
};