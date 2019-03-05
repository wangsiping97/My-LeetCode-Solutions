// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
// If the last word does not exist, return 0.
// Note: A word is defined as a character sequence consists of non-space characters only.

// Example:
// Input: "Hello World"
// Output: 5

#include <iostream> 
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = s.length();
        if (l == 0) return 0;
        int i = l - 1, count = 0;
        while (i >= 0 && s[i] == ' ') i--;
        while (i >= 0 && s[i] != ' ') {
            i--;
            count++;
        }
        return count;
    }
};