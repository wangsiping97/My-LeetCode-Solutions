// Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
// Note: The solution set must not contain duplicate subsets.

#include <vector> 
using namespace std; 

class Solution {
public:
    vector< vector<int> > subset;
    vector<int> tempsub;
    void dfs(int index, vector<int>& nums) {
        int n = nums.size();
        if (index > n) return;
        for (int i = index; i < n;) {
            int count = 0, next = i;
            while (next < n && nums[next] == nums[i]) {
                next++;
                count++;
            }
            for (int j = 1; j <= count; ++j) {
                for (int k = 1; k <= j; k++) tempsub.push_back(nums[i]);
                dfs(next, nums);
                for (int k = 1; k <= j; k++) tempsub.pop_back();
            }
            i = next;
        }
        subset.push_back(tempsub);
    }
    vector< vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(0, nums);
        return subset;
    }
};