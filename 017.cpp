// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

#include <iostream> 
#include <vector> 
#include <string> 
using namespace std;

class Solution {
public:
    vector<string> f(int i, string digits) {
        vector<string> ans;
        char bucket[8][4] = {{'a', 'b', 'c', '0'},
                            {'d', 'e', 'f', '0'}, 
                            {'g', 'h', 'i', '0'}, 
                            {'j', 'k', 'l', '0'}, 
                            {'m', 'n', 'o', '0'}, 
                            {'p', 'q', 'r', 's'}, 
                            {'t', 'u', 'v', '0'}, 
                            {'w', 'x', 'y', 'z'}};
        if (i == 0) {
            string str;
            str.reserve(1);
            for (int j = 0; j < 4; j++) {
                if (bucket[digits[i] - '0' - 2][j] != '0') {
                    str.append(1, bucket[digits[0] - '0' - 2][j]);
                    ans.push_back(str);
                    str.clear();
                }
            }
            return ans;
        }
        else {
            string str;
            str.reserve(i + 1);
            vector<string>::iterator iter;
            vector<string> prev = f(i - 1, digits);
            for (iter = prev.begin(); iter != prev.end(); iter++) {
                for (int j = 0; j < 4; j++) {
                    if (bucket[digits[i] - '0' - 2][j] != '0') {
                        str.append(*iter);
                        str.append(1, bucket[digits[i] - '0' - 2][j]);
                        ans.push_back(str);
                        str.clear();
                    }
                }
            }
            return ans;
        }
    }
    vector<string> letterCombinations(string digits) {
        int l = digits.length();
        if (l == 0) {
            vector<string> ans;
            return ans;
        }
        return f(l - 1, digits);
    }
};