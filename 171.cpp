// Given a column title as appear in an Excel sheet, return its corresponding column number.

#include <string> 
#include <cmath> 
using namespace std; 

class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        int l = s.length(); 
        for (int i = 0; i < l; ++i) {
            ans += pow(26, (l - i - 1)) * (s[i] + 1 - 'A');
        }
        return ans;
    }
};