// Given a set of distinct integers, nums, return all possible subsets (the power set).
// Note: The solution set must not contain duplicate subsets.

#include <vector> 
using namespace std; 

class Solution {
public:
    vector< vector<int> > ans; 
    vector<int> tempans;
    void dfs(int index, vector<int>& nums) {
        int n = nums.size();
        if (index > n) {
            return;
        }
        for (int i = index; i < n; ++i) {
            tempans.push_back(nums[i]);
            dfs(i + 1, nums);
            tempans.pop_back();
        }
        ans.push_back(tempans);
    }
    vector< vector<int> > subsets(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }
};