// Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

// Each letter in the magazine string can only be used once in your ransom note.

// Note:
// You may assume that both strings contain only lowercase letters.

// canConstruct("a", "b") -> false
// canConstruct("aa", "ab") -> false
// canConstruct("aa", "aab") -> true

#include <string> 
using namespace std; 

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int arr[128];
        int l1 = ransomNote.length(), l2 = magazine.length();
        if (l1 > l2) return false;
        memset(arr, 0, 128 * 4);
        for (int i = 0; i < l1; ++i) {
            arr[ransomNote[i]] ++;
            arr[magazine[i]] --;
        }
        for (int j = l1; j < l2; ++j) {
            arr[magazine[j]] --;
        }
        for (int k = 0; k < 128; ++k) {
            if (arr[k] > 0) return false;
        }
        return true;
    }
};

// Solution
// Bucket