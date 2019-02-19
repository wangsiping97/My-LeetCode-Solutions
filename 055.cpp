// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

// Example 1:
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.

// Example 2:
// Input: "cbbd"
// Output: "bb"

#include <iostream> 
using namespace std; 

class Solution {
public:
    string longestPalindrome(string s) {
        int  l = s.length();
        char ss[2 * l + 1];
        for (int i = 0; i < l; i++) {
            ss[2 * i] = '#';
            ss[2 * i + 1] = s[i];
        }
        ss[2 * l] = '#';
        int j_ = 0, r_ = 0;
        for (int j = 0; j < 2 * l + 1; j++) {
            int k = 1, r = 0;
            while (k <= j && j + k < 2 * l + 1 && ss[j - k] == ss[j + k]) {
                r++;
                k++;
            }
            if (r_ < r) {
                r_ = r;
                j_ = j;
            }
        }
        return s.substr(j_ / 2 - r_ / 2, r_);
    }
};

int main() {
    Solution s;
    cout << s.longestPalindrome("babad") << endl;
    // cout << s.longestPalindrome("cbbd") << endl;
    // cout << s.longestPalindrome("a") << endl;
    return 0;
}