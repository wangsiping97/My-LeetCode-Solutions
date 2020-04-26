// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

#include <iostream> 
#include <vector> 
#include <string> 
using namespace std;

class Solution {
public:
    vector<string> ans;
    string temp;
    void dfs(int index, vector<string>& bucket, string digits, int l) {
        if (index == l) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < bucket[digits[index] - '0' - 2].length(); ++i) {
            temp = temp + bucket[digits[index] - '0' - 2][i];
            dfs(index + 1, bucket, digits, l);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> bucket;
        bucket.push_back("abc");
        bucket.push_back("def");
        bucket.push_back("ghi");
        bucket.push_back("jkl");
        bucket.push_back("mno");
        bucket.push_back("pqrs");
        bucket.push_back("tuv");
        bucket.push_back("wxyz");
        int l = digits.length();
        if (l == 0) return ans;
        dfs(0, bucket, digits, l);
        return ans;
    }
};