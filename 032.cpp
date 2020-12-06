// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

// Example 1:
// Input: "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()"

// Example 2:
// Input: ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()"

#include <string> 
using namespace std; 

class Solution {
public:
    int longestValidParentheses(string s) {
        int l = s.length();
        if (l <= 1) return 0;
        int dp[l];
        memset(dp, 0, l * sizeof(int));
        if (s[0] == '(' && s[1] == ')') dp[1] = 2;
        int ans = max(0, dp[1]);
        for (int i = 2; i < l; ++i) {
            if (s[i] == ')' && s[i - 1] == '(') dp[i] = dp[i - 2] + 2;
            if (s[i] == ')' && s[i - 1] == ')')
                if ( i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
                    dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// Solution
// dp[i] := longest valid parenthese ending with s[i]
// if (s[i] == '(') dp[i] = 0;
// if (s[i] == ')' && s[i - 1] == '(') dp[i] = dp[i - 2] + 2;
// if (s[i] == ')' && s[i - 1] == ')' && s[i - dp[i - 1] - 1] == ')') dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2]; 