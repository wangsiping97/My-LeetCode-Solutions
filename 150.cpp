// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
// Valid operators are +, -, *, and /. Each operand may be an integer or another expression.
// Note that division between two integers should truncate toward zero.
// It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

#include <vector> 
#include <stack> 
#include <string>

using namespace std; 

class Solution {
public:
    int string2Int(string str) {
        int value = 0;
        int sign = 1;
        if (str[0] == '-') sign = -1;
        for (char c : str) {
            if (c == '-') continue;
            int t = c - '0';
            value *= 10;
            value += t;
        }
        return sign * value;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        stack.push(string2Int(tokens[0]));
        for (int i = 1; i < tokens.size(); ++i) {
            string token = tokens[i];
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int n1 = stack.top();
                stack.pop();
                int n2 = stack.top();
                stack.pop();
                if (token == "+")
                    stack.push(n1 + n2);
                else if (token == "-") 
                    stack.push(n2 - n1);
                else if (token == "*")
                    stack.push(n2 * n1);
                else stack.push(n2 / n1);
            } else {
                stack.push(string2Int(token));
            }
        }
        return stack.top();
    }
};