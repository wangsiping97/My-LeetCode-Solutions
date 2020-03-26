// Given a string s and a string t, check if s is subsequence of t.

// You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

#include <string> 
using namespace std; 

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        int m = s.length(), n = t.length();
        if (n == 0 && m != 0) return false;
        while (i < m) {
            while (j < n && t[j] != s[i]) j++;
            if (j == n) return false;
            i++;
            j++;
        }
        return true;
    }
};