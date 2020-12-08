// Given two strings s and t, return the number of distinct subsequences of s which equals t.
// A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).
// It's guaranteed the answer fits on a 32-bit signed integer.

#include <string> 
using namespace std; 

class Solution {
public:
    int numDistinct(string s, string t) {
        int ls = s.length(), lt = t.length();
        if (ls == 0 || lt == 0) return 0;
        long dp[ls + 1][lt + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = s[0] == t[0] ? 1 : 0;
        for (int i = 1; i < ls + 1; ++i) {
            dp[i][0] = s[i] == t[0] ? 1 + dp[i - 1][0] : dp[i - 1][0];
        }
        for (int i = 1; i < ls + 1; ++i) {
            for (int j = 1; j < lt + 1; ++j) {
                if (s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[ls][lt];
    }
};

// Solution
// dp[i][j] := num of distinct subsequences of s[0: i] to generate t[0 : j]
// if (s[i] != t[j]) dp[i][j] = dp[i - 1][j]
// else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
// initial: dp[0][0] = s[0] == t[0] ? 1 : 0
//          dp[i][0] = s[i] == t[0] ? 1 + dp[i - 1][0] : dp[i - 1][0]
// return -> dp[s.length()][t.length()]