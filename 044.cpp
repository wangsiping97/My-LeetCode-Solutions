// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.length();
        int n = p.length();
        bool dp[m + 1][n + 1];
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                dp[i][j] = false;
            }
        }
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                if (i == 0 && j == 0)
                    continue;
                if (i == 0)
                {
                    if (p[j - 1] == '*')
                        dp[i][j] = dp[i][j - 1];
                    else
                        dp[i][j] = false;
                }
                else
                {
                    if (j == 0)
                        dp[i][j] = false;
                    else if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                        dp[i][j] = dp[i - 1][j - 1];
                    else if (p[j - 1] == '*')
                        dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - 1] || dp[i][j - 1]);
                    else
                        dp[i][j] = false;
                }
            }
        }
        return dp[m][n];
    }
};

// Solution
// dp[i][j] := if s[:i] matches p[:j]
// dp[0][0] = true; dp[0][j] = ...; dp[i][0] =
// dp[i][j] =
//   if s[i] == p[j] or p[j] == '?' return dp[i-1][j-1]
//   else if p[j] == '*' return dp[i-1][j] || dp[i-1][j-1] || dp[i][j-1]
//   else return false