// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note:
// The same word in the dictionary may be reused multiple times in the segmentation.
// You may assume the dictionary does not contain duplicate words.

#include <string> 
#include <vector> 
using namespace std; 

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int l = s.length();
        if (l == 0) return true;
        if (wordDict.size() == 0) return false;
        bool dp[l][l];
        for (int diff = 0; diff < l; ++diff) {
            for (int i = 0; i + diff < l; ++i) {
                int j = i + diff;
                dp[i][j] = false;
                string temp = s.substr(i, diff + 1);
                for (int k = 0; k < wordDict.size(); ++k) {
                    if (wordDict[k] == temp) {
                        dp[i][j] = true;
                        break;
                    }
                }
                if (dp[i][j]) continue;
                for (int k = i; k <= j; ++k) {
                    if (dp[i][k] && dp[k + 1][j]) {
                        dp[i][j] = true;
                        break;
                    }
                }
            }
        }
        return dp[0][l - 1];
    }
};