// Given a string S and a string T, count the number of distinct subsequences of S which equals T.
// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

#include <string> 
using namespace std; 

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        if (m == 0 || n == 0) return 0;
        int ans[m + 1][n + 1];
        for (int i = 0; i < m + 1; ++i) {
            memset(ans[i], -1, (n + 1) * 4);
        }
        ans[0][0] = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n + 1; ++j) {
                if (ans[i][j] == 0) {
                    ans[i + 1][j] = 0;
                    if (s[i] == t[j]) ans[i + 1][j + 1] = 0;
                }
            }
            ans[i][n] = 1;
        }
        if (s[m - 1] == t[n - 1]) ans[m - 1][n - 1] = 1;
        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j < n; ++j) {
                if (ans[i][j] == 0) {
                    if (s[i] == t[j]) ans[i][j] = ans[i + 1][j] + ans[i + 1][j + 1];
                    else ans[i][j] = ans[i + 1][j];
                }
            }
        }
        return ans[0][0];
    }
};