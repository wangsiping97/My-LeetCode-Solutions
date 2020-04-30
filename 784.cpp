// Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

#include <vector> 
#include <string> 
#include <cstdlib> 
using namespace std; 

class Solution {
public:
    string temp;
    vector<string> ans; 
    void dfs(string str, int index, int* isLetter) {
        if (index == str.length()) {
            ans.push_back(temp);
            return; 
        }
        if (isLetter[index] == 1) {
            temp[index] = str[index];
            dfs(str, index + 1, isLetter);
            temp[index] = str[index] + 'A' - 'a'; // lower-case to upper-case
            dfs(str, index+1, isLetter);
        }
    }
    vector<string> letterCasePermutation(string S) {
        int l = S.length();
        int* isLetter = (int*)malloc(l * sizeof(int));
        memset(isLetter, 0, l * sizeof(int));
        for (int i = 0; i < l; ++i) {
            if (S[i] >= '0' && S[i] <= '9') continue;
            isLetter[i] = 1;
            if (S[i] >= 'A' && S[i] <= 'Z') {
                S[i] = S[i] - 'A' + 'a';
            }
        }
        temp.assign(S.begin(), S.end());
        dfs(S, 0, isLetter);
        return ans;
    }
};