// Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

// Example 1:
// Input: "aba"
// Output: True

// Example 2:
// Input: "abca"
// Output: True
// Explanation: You could delete the character 'c'.

// Note:
// The string will only contain lowercase characters a-z. The maximum length of the string is 50000.

#include <string> 
using namespace std; 

class Solution {
public:
    bool solve(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l = s.length();
        for (int i = 0; i < l; ++i) {
            if (s[i] != s[l - 1 - i])
                return solve(s, i + 1, l - 1 - i) || solve(s, i, l - 2 - i);
        }
        return true;
    }
};