// Implement a basic calculator to evaluate a simple expression string.
// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

#include <string> 
#include <iostream> 
using namespace std; 

class Solution {
public:
    int calculate(string s) {
        int sign = 1;
        int l = s.length();
        int ans = 0, num = 0;
        for (int i = 0; i < l; ++i) {
            // important: backtracking
            if (s[i] == '(') {
                int j = i, count = 0;
                // important
                for(; j < l; ++j) {
                    if (s[j] == '(') count++;
                    if (s[j] == ')') count--;
                    if (count == 0) break;
                }
                num = calculate(s.substr(i + 1, j - i - 1));
                i = j;
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                num = s[i] - '0' + num * 10;
            }
            else if (s[i] == '+') {
                ans += sign * num;
                num = 0;
                sign = 1;
            }
            else if (s[i] == '-') {
                ans += sign * num;
                num = 0;
                sign = -1;
            }
        }
        ans += sign * num;
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.calculate("2-4-(8+2-6+(8+4-(1)+8-10))") << endl;
}