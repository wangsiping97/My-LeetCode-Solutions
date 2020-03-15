// Given two strings s and t, determine if they are isomorphic.
// Two strings are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

// Example 1:
// Input: s = "egg", t = "add"
// Output: true

// Example 2:
// Input: s = "foo", t = "bar"
// Output: false

// Example 3:
// Input: s = "paper", t = "title"
// Output: true

// Note:
// You may assume both s and t have the same length.

#include <string> 
using namespace std; 

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int arr[128];
        memset(arr, -1, 128*4);
        int l = s.length();
        for (int i = 0; i < l; ++i) {
            if (arr[s[i]] == -1) arr[s[i]] = i;
            s[i] = arr[s[i]];
        }
        memset(arr, -1, 128*4);
        for (int i = 0; i < l; ++i) {
            if (arr[t[i]] == -1) arr[t[i]] = i;
            t[i] = arr[t[i]];
        }
        return s == t;
    }
};

// Solution
// Bucket