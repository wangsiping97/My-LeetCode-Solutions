// Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

// Example 1:
// Input: ["abcd","dcba","lls","s","sssll"]
// Output: [[0,1],[1,0],[3,2],[2,4]] 
// Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]

// Example 2:
// Input: ["bat","tab","cat"]
// Output: [[0,1],[1,0]] 
// Explanation: The palindromes are ["battab","tabbat"]

#include <vector> 
#include <string> 
#include <map>
#include <cstdlib>
using namespace std; 

class Solution {
public:
    vector< vector<int> > palindromePairs(vector<string>& words) {
        vector< vector<int> > ans;
        ans.clear();
        map<string, int> m;
        int l = words.size();
        if (l == 0) return ans;
        for (int i = 0; i < l; ++i) {
            string temp = words[i];
            reverse(temp.begin(), temp.end());
            m[temp] = i;
        }

        for (int i = 0; i < l; ++i) {
            int ll = words[i].length();
            int len;
            for (len = 0; len <= ll; ++len) {
                map<string, int>::iterator iter = m.find(words[i].substr(0, len));
                if (iter == m.end() || i == iter->second) continue;
                string res = words[i].substr(len);
                int lres = res.length();
                bool flag = true;
                for (int i = 0; i < lres / 2; ++i) 
                    if (res[i] != res[lres - 1 - i]) {
                        flag = false;
                        break;
                    }
                if (flag) {
                    vector<int> thisAns;
                    thisAns.push_back(i);
                    thisAns.push_back(iter->second);
                    ans.push_back(thisAns);
                }
            }
            for (len = 0; len <= ll; ++len) {
                map<string, int>::iterator iter = m.find(words[i].substr(ll - len, len));
                if (iter == m.end() || i == iter->second) continue;
                string res = words[i].substr(0, ll - len);
                int lres = res.length();
                if (lres == 0 && len != 0) continue;
                bool flag = true;
                for (int i = 0; i < lres / 2; ++i) 
                    if (res[i] != res[lres - 1 - i]) {
                        flag = false;
                        break;
                    }
                if (flag) {
                    vector<int> thisAns;
                    thisAns.push_back(iter->second);
                    thisAns.push_back(i);
                    ans.push_back(thisAns);
                }
            }
            
        }
        return ans;
    }
};