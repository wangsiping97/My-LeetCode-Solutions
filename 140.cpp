// Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

#include <vector>
#include <string> 
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<string> temp;
    unordered_set<string> wordSet;
    void dfs(string s, int pos) {
        int l = s.size();
        if (pos == l) {
            res.emplace_back(temp);
            return;
        }
        string tempStr;
        for (int i = pos; i < l; ++i) {
            tempStr.push_back(s[i]);
            if (wordSet.find(tempStr) != wordSet.end()) {
                temp.emplace_back(tempStr);
                dfs(s, i+1);
                temp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (string word : wordDict) 
            wordSet.insert(word);
        dfs(s, 0);
        vector<string> answer;
        for (vector<string> v: res) {
            string resStr;
            for (string str : v) {
                resStr = resStr + str;
                resStr.push_back(' ');
            }
            resStr.pop_back();
            answer.emplace_back(resStr);
        }
        return answer;
    }
};