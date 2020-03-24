// Given a string, your task is to count how many palindromic substrings in this string.
// The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

// Example 1:
// Input: "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".

// Example 2:
// Input: "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

// Note:
// The input string length won't exceed 1000.

#include <string> 
#include <iostream>
using namespace std; 

class Solution {
public:
    int countSubstrings(string s) {
        int l = s.length();
        if (l == 0) return 0;
        int dp[l][l];
        int isPalindromic[l][l];
        for (int i = 0; i < l; ++i) {
            memset(dp[i], 0, l * 4);
            memset(isPalindromic[i], 0, l * 4);
        }
        for (int j = 0; j < l; ++j)
            for (int i = 0; i + j < l; ++i) {
                if (j == 0) {
                    dp[i][i] = 1;
                    isPalindromic[i][i] = 1;
                    continue;
                }
                dp[i][i + j] =  dp[i][i + j - 1] + dp[i + 1][i + j] - dp[i + 1][i + j - 1];
                if (s[i] == s[i + j]) {
                    if (j == 1) {
                        dp[i][i + 1] = 3;
                        isPalindromic[i][i + 1] = 1;
                    }
                    else if (isPalindromic[i + 1][i + j - 1] == 1) {
                        isPalindromic[i][i + j] = 1;
                        dp[i][i + j] += 1;
                    }
                }
            }
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < l; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[0][l - 1];
    }
};

int main() {
    Solution s;
    cout << s.countSubstrings("abc");
}