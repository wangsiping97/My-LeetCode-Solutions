// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
// Note: For the purpose of this problem, we define empty string as valid palindrome.

// Example 1:
// Input: "A man, a plan, a canal: Panama"
// Output: true

// Example 2:
// Input: "race a car"
// Output: false

#include <string> 
using namespace std; 

class Solution {
public:
    bool isPalindrome(string s) {
        if (s == "") return true;
        int l = s.length();
        int start = 0, end = l - 1;
        while (start < end) {
            while (start < end && (s[start] < '0' || s[start] > '9') && (s[start] < 'A' || s[start] > 'Z') && (s[start] < 'a' || s[start] > 'z'))
                start++;
            while (end > start && (s[end] < '0' || s[end] > '9') && (s[end] < 'A' || s[end] > 'Z') && (s[end] < 'a' || s[end] > 'z'))
                end--;
            s[start] = s[start] < 'a' ? s[start] - 'A' : s[start] - 'a';
            s[end] = s[end] < 'a' ? s[end] - 'A' : s[end] - 'a';
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};

// Solution
// Two pointers