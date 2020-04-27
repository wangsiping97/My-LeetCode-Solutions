// Implement a basic calculator to evaluate a simple expression string.
// The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

#include <string> 
#include <stack> 
#include <iostream> 
using namespace std; 

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int l = s.length();
        int num = 0, ans = 0, sign = 1;
        for (int i = 0; i < l; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = s[i] - '0' + num * 10;
            }
            else if (s[i] == '+') {
                st.push(sign * num);
                num = 0;
                sign = 1;
            }
            else if (s[i] == '-') {
                st.push(sign * num);
                num = 0;
                sign = -1;
            }
            else if (s[i] == '*') {
                st.push(sign * num);
                num = 0;
                sign = 1;
                int j = i + 1;
                for (; j < l; ++j) {
                    if (s[j] >= '0' && s[j] <= '9')
                        num = s[j] - '0' + num * 10;
                    if (s[j] == '+' || s[j] == '-' || s[j] == '*' || s[j] == '/') break;
                }
                num = st.top() * num;
                st.pop();
                i = j - 1;
            }
            else if (s[i] == '/') {
                st.push(sign * num);
                num = 0;
                sign = 1;
                int j = i + 1;
                for (; j < l; ++j) {
                    if (s[j] >= '0' && s[j] <= '9')
                        num = s[j] - '0' + num * 10;
                    if (s[j] == '+' || s[j] == '-' || s[j] == '*' || s[j] == '/') break;
                }
                i = j - 1;
                num = st.top() / num;
                st.pop();
            }
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans + num;
    }
};

int main() {
    Solution s;
    cout << s.calculate("3 + 5 / 2 * 4  + 8 * 2") << endl;
}

// Solution
// 由于存在运算优先级，我们采取的措施是使用一个栈保存数字，如果该数字之前的符号是加或减，那么把当前数字压入栈中，注意如果是减号，则加入当前数字的相反数，因为减法相当于加上一个相反数。如果之前的符号是乘或除，那么从栈顶取出一个数字和当前数字进行乘或除的运算，再把结果压入栈中，那么完成一遍遍历后，所有的乘或除都运算完了，再把栈中所有的数字都加起来就是最终结果了