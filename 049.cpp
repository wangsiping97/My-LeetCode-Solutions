// Given an array of strings, group anagrams together.
// Example:
// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// Note:
// All inputs will be in lowercase.
// The order of your output does not matter.

#include <iostream> 
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector< vector<string> > groupAnagrams(vector<string>& strs) {
        vector< vector<string> > ans;
        int n = strs.size();
        if (n == 0) return ans;
        map< vector<char>, vector<string> > m;
        for (int i = 0; i < n; i++) {
            int l = strs[i].length();
            vector<char> v;
            for (int j = 0; j < l; j++) {
                v.push_back(strs[i][j]);
            }
            sort(v.begin(), v.end());
            m[v].push_back(strs[i]);
        }
        map< vector<char>, vector<string> >::iterator iter = m.begin();
        while (iter != m.end()) {
            ans.push_back(iter->second);
            iter++;
        }
        return ans;
    }
};