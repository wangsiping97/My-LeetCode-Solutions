// You are given an array of binary strings strs and two integers m and n.
// Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
// A set x is a subset of a set y if all elements of x are also elements of y.

#include <string> 
#include <vector> 
using namespace std; 

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int count0, count1;
        vector<int> a, b;
        for (string str : strs) {
            count0 = count1 = 0;
            for (char c : str) {
                if (c == '1') count1++;
                else count0++;
            }
            a.push_back(count0);
            b.push_back(count1);
        }
        int l = strs.size();
        if (l == 0) return 0;
        long long helper[m + 1][n + 1];
        for (int j = 0; j < m + 1; ++j) {
            for(int k = 0; k < n + 1; ++k) {
                if (j >= a[0] && k >= b[0]) helper[j][k] = 1;
                else helper[j][k] = 0;
            }
        }
        for (int i = 1; i < l; ++i) {
            for (int j = m; j >= 0; --j) {
                for (int k = n; k >= 0; --k) {
                    if (j >= a[i] && k >= b[i]) {
                        helper[j][k] = max(helper[j - a[i]][k - b[i]] + 1, helper[j][k]);
                    }
                }
            }
        }
        return helper[m][n];
    }
};

// Solution
// dp[i][j][k] := having considered first i str, and have j 0s and k 1s.
// dp[i][j][k] = max{dp[i - 1][j - a[i]][k - b[i]] + 1, dp[i - 1][j][k]} if (j >= a[i] && k >= b[i])
//               dp[i - 1][j][k] otherwise
// Space optimization