// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

#include <vector> 
#include <iostream>
using namespace std;

class Solution {
public:
    vector< vector<int> > ans;
    vector<int> tempans;
    void dfs(int index, int n, int k) {
        if (tempans.size() == k) {
            ans.push_back(tempans);
            return;
        }
        if (index > n) return;
        for (int i = index; i <= n; ++i) {
            tempans.push_back(i);
            dfs(i + 1, n, k);
            tempans.pop_back();
        }
    }
    vector< vector<int> > combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }
};