// Given a string with possible duplicate characters, return a list with all permutations of the characters.

// Examples
// Set = “abc”, all permutations are [“abc”, “acb”, “bac”, “bca”, “cab”, “cba”]
// Set = "aba", all permutations are ["aab", "aba", "baa"]
// Set = "", all permutations are [""]
// Set = null, all permutations are []

#include <vector> 
#include <string> 
using namespace std; 

class Solution {
public:
    vector<string> ans;
    string temp;
    int* count;
    void dfs(string input, int n) {
        if (temp.length() == n) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < 128; ++i) {
            if (count[i] > 0) {
                count[i] --;
                temp.push_back(i + ' ');
                dfs(input, n);
                temp.pop_back();
                count[i] ++;
            }
        }
    }
    vector<string> permutations(string input) {
        // write your solution here
        int n = input.length();
        if (n == 0) {
            ans.push_back("");
            return ans; 
        }
        count = new int[128];
        memset(count, 0, n * sizeof(bool));
        for (int i = 0; i < n; ++i) {
            count[input[i] - ' ']++;
        }
        dfs(input, n);
        delete count;
        return ans;
    }
};
