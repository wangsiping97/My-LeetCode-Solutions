// Given an array nums that represents a permutation of integers from 1 to n. We
// are going to construct a binary search tree (BST) by inserting the elements
// of nums in order into an initially empty BST. Find the number of different
// ways to reorder nums so that the constructed BST is identical to that formed
// from the original array nums. For example, given nums = [2,1,3], we will have
// 2 as the root, 1 as a left child, and 3 as a right child. The array [2,3,1]
// also yields the same BST but [3,2,1] yields a different BST. Return the
// number of ways to reorder nums such that the BST formed is identical to the
// original BST formed from nums. Since the answer may be very large, return it
// modulo 109 + 7.

#include <vector>
using namespace std;

class Solution {
 public:
  int MOD = 1000000007;
  int c[1010][1010];
  void make_c() {
    c[0][0] = 1;
    for (int i = 1; i <= 1000; ++i) {
      c[i][0] = 1;
      c[i][i] = 1;
      for (int j = 1; j < i; ++j) {
        c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
      }
    }
  }
  int dfs(vector<int>& nums) {
    if (nums.size() == 1) return 1;
    vector<int> left;
    vector<int> right;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[0]) {
        right.push_back(nums[i]);
      } else {
        left.push_back(nums[i]);
      }
    }
    if (right.empty()) {
      return dfs(left);
    }
    if (left.empty()) {
      return dfs(right);
    }
    int left_res = dfs(left);
    int right_res = dfs(right);
    int m = left.size() + right.size();
    int n = left.size();
    long long result = (long long)c[m][n] * left_res % MOD;
    return result * right_res % MOD;
  }
  int numOfWays(vector<int>& nums) {
    make_c();
    return dfs(nums) - 1;
  }
};