// Return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.

#include <string> 
#include <stack> 
using namespace std; 

class Solution {
public:
    string smallestSubsequence(string s) {
        int l = s.length();
        string ans;
        if (l == 0) return ans;
        int bucket[26];
        bool add[26];
        memset(bucket, 0, 26 * sizeof(int));
        memset(add, 0, 26 * sizeof(bool));
        for (char c : s) 
            bucket[c - 'a']++;
        for (int i = 0; i < l; ++i) {
            if (add[s[i] - 'a'] == true) {
                bucket[s[i] - 'a']--;
                continue;
            }
            if (ans.empty()) {
                ans.push_back(s[i]);
                add[s[i] - 'a'] = true;
                bucket[s[i] - 'a']--;
                continue;
            }
            if (s[i] > ans.back()) {
                ans.push_back(s[i]);
                add[s[i] - 'a'] = true;
                bucket[s[i] - 'a']--;
            } 
            else {
                while(!ans.empty() && ans.back() > s[i] && bucket[ans.back() - 'a'] > 0) {
                    add[ans.back() - 'a'] = false;
                    ans.pop_back();
                }
                ans.push_back(s[i]);
                add[s[i] - 'a'] = true;
                bucket[s[i] - 'a']--;
            }
        }
        return ans;
    }
};

// Solution
// 单调栈