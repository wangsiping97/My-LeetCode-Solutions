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
#include <set>
using namespace std;

class Solution {
public:
    vector< vector<string> > groupAnagrams(vector<string>& strs) {
        vector< vector<string> > ans;
        int n = strs.size();
        if (n == 0) return ans;
        vector<string> temps;
        int j, k = 0;
        for (int i = 0; i < n; i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            j = 0;
            while (j < k && temp > ans[j].back()) {
                j++;
            }
            if (temp == ans[j].back()) {
                ans[j].pop_back();
                ans[j].push_back(strs[i]);
                ans[j].push_back(temp);
                break;
            }
            if (j == k) {
                vector<string> v;
                v.push_back(strs[i]);
                v.push_back(temp);
                ans.push_back(v);
                k++;
            }
        }
        vector< vector<string> >::iterator iter;
        for (iter = ans.begin(); iter != ans.end(); iter++) {
            iter->pop_back();
        }
        return ans;
    }
};