// Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

#include <string> 
using namespace std; 

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int l = s.length();
        if (l == 0) return 0;
        int dp[l][l];
        for (int j = 0; j < l; ++j)
            for (int i = 0; i + j < l; ++i) {
                if (j == 0) dp[i][i] = 1;
                else if (s[i] == s[i + j])
                    dp[i][i + j] = j == 1 ? 2 : 2 + dp[i + 1][i + j - 1];
                else 
                    dp[i][i + j] = max(dp[i][i + j - 1], dp[i + 1][i + j]);
            }
        return dp[0][l - 1];
    }
};

// Solution
// Dynamic Programming: dp[i][j]: longest palindromic subsequence from s[i] to s[j]. 
// Find the relation between dp[i][j] and dp[i][j-1], dp[i+1][j], dp[i+1][j-1]. 