// Given a string, find the length of the longest substring without repeating characters.

// Example 1:
// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 

// Example 2:
// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:
// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3. 

#include <iostream> 
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int bucket[128];
        for (int i = 0; i < 128; i++) 
            bucket[i] = 0;
        int start = 0, count = 0, l = s.length();
        for (int i = 0; i < l; i++) {
            if (bucket[(int)s[i]] != 0) {
                if (i - start > count) count = i - start;
                if (bucket[(int)s[i]] > start) start = bucket[(int)s[i]];
            }
            bucket[(int)s[i]] = i + 1;
        }
        return count > l - start ? count : l - start;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << s.lengthOfLongestSubstring("bbbbb") << endl;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
    cout << s.lengthOfLongestSubstring(". ++...") << endl;
    cout << s.lengthOfLongestSubstring("aa") << endl;
    cout << s.lengthOfLongestSubstring("aab") << endl;
    return 0;
}