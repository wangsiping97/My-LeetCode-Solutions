// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

// Examples:
// s = "leetcode"
// return 0.

// s = "loveleetcode",
// return 2.

// Note: You may assume the string contain only lowercase letters.

#include <string> 
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26];
        for (int i = 0; i < s.length(); ++i) {
            arr[s[i] - 'a']++;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (arr[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};

// Solution
// 1. Bucket sorting