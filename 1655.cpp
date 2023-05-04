// You are given an array of n integers, nums, where there are at most 50 unique
// values in the array. You are also given an array of m customer order
// quantities, quantity, where quantity[i] is the amount of integers the ith
// customer ordered. Determine if it is possible to distribute nums such that:

// The ith customer gets exactly quantity[i] integers,
// The integers the ith customer gets are all equal, and
// Every customer is satisfied.
// Return true if it is possible to distribute nums according to the above
// conditions.

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  unordered_map<int, int> integers;
  bool dfs(vector<int>& quantity, int idx) {
    if (idx == quantity.size()) return true;
    unordered_map<int, int>::iterator iter;
    for (iter = integers.begin(); iter != integers.end(); iter++) {
      if (iter->second >= quantity[idx]) {
        iter->second -= quantity[idx];
        bool res = dfs(quantity, idx + 1);
        iter->second += quantity[idx];
        if (res) return true;
      }
    }
    return false;
  }
  bool canDistribute(vector<int>& nums, vector<int>& quantity) {
    sort(quantity.begin(), quantity.end(), greater<int>());
    for (int num : nums) {
      integers[num]++;
    }
    return dfs(quantity, 0);
  }
};