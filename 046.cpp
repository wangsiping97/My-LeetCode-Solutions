// Given a collection of distinct integers, return all possible permutations.

// Example:

// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

#include <iostream> 
#include <vector>
using namespace std;

class Solution {
public:
    vector< vector<int> > permutes;
    vector<int> temp;
    vector<bool> isUsed;
    void dfs(vector<int>& nums, int n) {
        if (temp.size() == n) permutes.push_back(temp);
        if (temp.size() > n) return;
        for (int i = 0; i < n; ++i) {
            if (isUsed[i] == false) {
                isUsed[i] = true;
                temp.push_back(nums[i]);
                dfs(nums, n);
                temp.pop_back();
                isUsed[i] = false;
            }
        }
    }
    vector< vector<int> > permute(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            isUsed.push_back(false);
        dfs(nums, n);
        return permutes;
    }
};