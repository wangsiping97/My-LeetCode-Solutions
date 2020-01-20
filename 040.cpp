// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
// Each number in candidates may only be used once in the combination.

// Note:
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.

#include <iostream> 
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    set< vector<int> > res;
    vector<int> tempans;
    void dfs(vector<int>& candidates, int target, int start) {
        if (start > candidates.size() || target < 0) return;
        if (target == 0) {
            res.insert(tempans);
            return;
        }
        if (start < candidates.size()) {
            tempans.push_back(candidates[start]);
            dfs(candidates, target - candidates[start], start + 1);
            tempans.pop_back();
            dfs(candidates, target, start + 1);
        }
    }
    vector< vector<int> > combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), greater<int>());
        dfs(candidates, target, 0);
        vector< vector<int> > vres;
        vres.assign(res.begin(), res.end());
        return vres;
    }
};