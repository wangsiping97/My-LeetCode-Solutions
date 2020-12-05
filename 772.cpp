// Implement a basic calculator to evaluate a simple expression string.
// The expression string contains only non-negative integers, +, -, *, / operators , open ( and closing parentheses ) and empty spaces . The integer division should truncate toward zero.
// You may assume that the given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647].
// Follow up: Could you solve the problem without using built-in library functions.

#include <string> 
using namespace std; 

class Solution {
public:
    int calculate(string s) {
        long long ans = 0;
        long long cur = 0;
        long long top = 0;
        int l = s.length();
        char op = '+';
        for (int i = 0; i < l; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                cur *= 10;
                cur += s[i] - '0';
            }
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i == l - 1) {
                switch(op) {
                    case '+': top += cur; break;
                    case '-': top -= cur; break;
                    case '*': top *= cur; break;
                    case '/': top /= cur; break;
                    default: break;
                }
                if (s[i] == '+' || s[i] == '-' || i == l - 1) {
                    ans += top;
                    top = 0;
                }
                op = s[i];
                cur = 0;
            }
            if (s[i] == '(') {
                int j = i + 1;
                int count = 1;
                while (j < l && count > 0) {
                    if (s[j] == '(') count++;
                    if (s[j] == ')') count--;
                    j++;
                }
                cur = calculate(s.substr(i + 1, j - i - 2));
                i = j - 2; 
            }
        }
        return ans;
    }
};

// Solution
// for (...) -> backtracking
// without parentheses: * /
// stack
// followup - using O(1) space: only keep the top of the stack