// Given a collection of numbers that might contain duplicates, return all possible unique permutations.

#include <vector> 
using namespace std; 

class Solution {
public:
    vector< vector<int> > permutes;
    vector<int> temp;
    vector<bool> isUsed;
    void dfs(int index, vector<int>& nums, int n) {
        if (temp.size() == n) {
            permutes.push_back(temp);
            return;
        }
        if (temp.size() > n) return;
        for (int j = index; j < n; ++j) {
            for (int i = 0; i < n;) {
                int next = i + 1;
                if (isUsed[i] == false) {
                    while (next < n && nums[next] == nums[i]) next++;
                    isUsed[i] = true;
                    temp.push_back(nums[i]);
                    dfs(j + 1, nums, n);
                    temp.pop_back();
                    isUsed[i] = false;
                }
                i = next;
            }
        }
    }
    vector< vector<int> > permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            isUsed.push_back(false);
        dfs(0, nums, n);
        return permutes;
    }
};