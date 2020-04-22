// Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

// Note:
// All numbers will be positive integers.
// The solution set must not contain duplicate combinations.

#include <vector> 
using namespace std; 

class Solution {
public:
    vector< vector<int> > ans;
    vector<int> tempans;
    void dfs (int i, int k, int n) {
        if (n == 0 && tempans.size() == k) {
            ans.push_back(tempans);
            return;
        }
        if (n < 0 || i > 9) return; 
        for (int index = i; index <= 9; ++index) {
            tempans.push_back(index);
            dfs(index + 1, k, n - index);
            tempans.pop_back();
        }
    }
    vector< vector<int> > combinationSum3(int k, int n) {
        dfs(1, k, n);
        return ans;
    }
};