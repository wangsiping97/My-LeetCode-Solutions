// Implement a basic calculator to evaluate a simple expression string.
// The expression string contains only non-negative integers, +, -, *, / operators , open ( and closing parentheses ) and empty spaces . The integer division should truncate toward zero.
// You may assume that the given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647].
// Follow up: Could you solve the problem without using built-in library functions.

#include <string> 
using namespace std; 

class Solution {
public:
    int calculate(string s) {
        int num = 0; // current number
        int curres = 0; // current result
        int ans = 0; // final result
        int count = 0; 
        char c;
        char op = '+';
        int l = s.length();
        for (int i = 0; i < l; ++i) {
            c = s[i];
            if (c >= '0' && c <= '9') {
                // deal with integer overflow
                if (num == 214748364 && c == '8') {
                    num = -num;
                    op = '+';
                }
                num = num >= 0 ? num * 10 - '0' + c : num * 10 + '0' - c;
            }
            else if (c == '(') {
                count++;
                for (int j = i + 1; j < l; ++j) {
                    if (s[j] == '(') count++;
                    else if (s[j] == ')') count--;
                    if (count == 0) {
                        num = calculate(s.substr(i + 1, j - i -1));
                        i = j;
                        break;
                    }
                }
            }
            if (c == '+' || c == '-' || c == '*' || c == '/' || i == l - 1) {
                switch(op) {
                    case '+': curres += num; break;
                    case '-': curres -= num; break;
                    case '*': curres *= num; break;
                    case '/': curres /= num; break;
                }
                if (c == '+' || c == '-' || i == l - 1) {
                    ans += curres;
                    curres = 0;
                }
                op = c;
                num = 0;
            }
        }
        return ans;
    }
};