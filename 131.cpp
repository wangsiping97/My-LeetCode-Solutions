// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return all possible palindrome partitioning of s.

#include <string> 
#include <vector> 
using namespace std; 

class Solution {
public:
    vector< vector<string> > ans;
    vector<string> temp;
    void dfs(int index, string s, int l) {
        if (index == l) {
            ans.push_back(temp);
            return;
        }
        for (int i = index; i < l; ++i) {
            if (s[i] == s[index]) {
                bool flag = true;
                for (int j = 0; j < (i - index + 1) / 2; ++j)
                    if (s[index + j] != s[index + i - index - j]) {
                        flag = false;
                        break;
                    }
                if (flag) {
                    string str = s.substr(index, i - index + 1);
                    temp.push_back(str);
                    dfs(i + 1, s, l);
                    temp.pop_back();
                }
            }
        }
    }
    vector< vector<string> > partition(string s) {
        int l = s.length();
        dfs(0, s, l);
        return ans;
    }
};