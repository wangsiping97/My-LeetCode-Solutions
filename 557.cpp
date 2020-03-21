// Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

// Example 1:
// Input: "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"

#include <string> 
using namespace std; 

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        if (s == "") return ans;
        int start = 0, end = 0;
        int ll;
        char temp;
        int l = s.length();
        while (start < l) {
            while (end < l && s[end] != ' ')
                end++;
            ll = end - start;
            for (int i = 0; i < ll / 2; ++i) {
                temp = s[start + i];
                s[start + i] = s[end - 1 - i];
                s[end - 1 - i] = temp;
            }
            start = end + 1;
            end = start;
        }
        return s;
    }
};

// Solution
// Two pointers