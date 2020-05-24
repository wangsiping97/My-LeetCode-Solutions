// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

#include <vector> 
using namespace std; 

class Solution {
public:
    int minimumTotal(vector< vector<int> >& triangle) {
        if (triangle.empty() || triangle[0].empty()) return 0;
        int n = triangle.size();
        vector< vector<int> > dp(n); // dp[i][j] = min path sum to triangle[i][j]
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (i == 0 && j == 0) dp[i].push_back(triangle[i][j]);
                else if (j == 0) dp[i].push_back(dp[i - 1][0] + triangle[i][j]);
                else if (j == i) dp[i].push_back(dp[i - 1][i - 1] + triangle[i][j]);
                else dp[i].push_back(min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j]);
                if (i == n - 1) ans = min(ans, dp[i][j]);
            }
        }
        return ans;
    }
};