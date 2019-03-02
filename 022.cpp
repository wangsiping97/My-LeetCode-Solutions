// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// For example, given n = 3, a solution set is:
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack> 
using namespace std;

class Solution {
public:
    bool check(string str) {
        vector<char> test;
        test.push_back('0');
        for (int i = 0; i < str.length(); i++) {
            if (str[i] - test.back() == 1) test.pop_back();
            else test.push_back(str[i]);
        }
        return test.size() == 1;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (n == 0) return ans;
        string str;
        str.reserve(2 * n);
        for (int i = 0; i < n; i++) str.append(1, '(');
        for (int i = n; i < 2 * n; i++) str.append(1, ')');
        do {
            if (check(str)) ans.push_back(str);
        } while(next_permutation(str.begin(), str.end()));
        return ans;
    }
};