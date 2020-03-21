// Write a function that takes a string as input and reverse only the vowels of a string.

// Example 1:
// Input: "hello"
// Output: "holle"

// Example 2:
// Input: "leetcode"
// Output: "leotcede"

// Note:
// The vowels does not include the letter "y".

#include <string> 
using namespace std; 

class Solution {
public:
    string reverseVowels(string s) {
        if (s == "") return s;
        int start = 0, end = s.length() - 1;
        char temp;
        while (start < end) {
            while (start < end && s[start] != 'a' && s[start] != 'A' && s[start] != 'e' && s[start] != 'E' && s[start] != 'i' && s[start] != 'I' && s[start] != 'o' && s[start] != 'O' && s[start] != 'u' && s[start] != 'U')
                start++;
            while (end > start && s[end] != 'a' && s[end] != 'A' && s[end] != 'e' && s[end] != 'E' && s[end] != 'i' && s[end] != 'I' && s[end] != 'o' && s[end] != 'O' && s[end] != 'u' && s[end] != 'U')
                end--;
            temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
        return s;
    }
};

// Solution
// Two pointers (notice: borders!)