// Implement strStr().
// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Example 1:
// Input: haystack = "hello", needle = "ll"
// Output: 2

// Example 2:
// Input: haystack = "aaaaa", needle = "bba"
// Output: -1

// Clarification:
// What should we return when needle is an empty string? This is a great question to ask during an interview.
// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

#include <iostream> 
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i, j, k;
        int len1 = haystack.length(), len2 = needle.length();
        for (i = 0; i < len1 - len2 + 1; i++) {
            for (j = 0, k = i; j < needle.length(); j++, k++) {
                if (haystack[k] != needle[j])
                    break;
            }
            if (j == needle.length())
                return i;
        }
        return needle.empty() ? 0 : -1;
    }
};

int main() {
    Solution s;
    string haystack = "a";
    string needle = "a";
    cout << s.strStr(haystack, needle) << endl;
    return 0;
}