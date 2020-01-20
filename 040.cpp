// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
// Each number in candidates may only be used once in the combination.

// Note:
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.

#include <iostream> 
#include <vector>
using namespace std;

class Solution {
public:
    vector< vector<int> > res;
    vector<int> tempans;
    void dfs(vector<int>& candidates, int target, int start) {
        if (target == 0) {
            res.push_back(tempans);
            return;
        }
        if (start >= candidates.size()) return;
        tempans.push_back(candidates[start]);
        target -= candidates[start];
        
        for (int i = start + 1; i <= candidates.size(); ++i)
            dfs(candidates, target, i);
        tempans.pop_back();
        target += candidates[start];
    }
    vector< vector<int> > combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), greater<int>());
        for (int i = 0; i < candidates.size(); ++i) 
            dfs(candidates, target, i);
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};