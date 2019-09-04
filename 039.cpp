// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
// The same repeated number may be chosen from candidates unlimited number of times.

// Note:
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.

// Example 1:
// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]

// Example 2:
// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]

#include <iostream> 
#include <vector>
#define pb push_back
using namespace std;

class Solution {
public:
    vector< vector<int> > res;
    vector<int> ans;
    void dfs(int i, int target, vector<int>& candidates) {
        if (i > candidates.size()) return;
        if (target == 0) {
            res.push_back(ans);
            return;
        }
        if (i < candidates.size()) {
            int t = target / candidates[i];
            for (int j = 0; j <= t; j--) {
                for (int k = 0; k < j; k++) ans.push_back(candidates[i]);
                dfs(i + 1, target - j * candidates[i], candidates);
                for (int k = 0; k < j; k++) ans.pop_back();
            }
        }
    }
    vector< vector<int> > combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), greater<int>());
        dfs(0, target, candidates);
        return res;
    }
};