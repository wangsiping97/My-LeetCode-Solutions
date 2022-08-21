// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int bucket_s[26];
        int bucket_t[26];
        memset(bucket_s, 0, sizeof(bucket_s));
        memset(bucket_t, 0, sizeof(bucket_t));
        for (char c : s) 
            bucket_s[c - 'a']++;
        for (char c : t) 
            bucket_t[c - 'a']++;
        for (int i = 0; i < 26; ++i) {
            if (bucket_s[i] != bucket_t[i])
                return false;
        }
        return true;
    }
};