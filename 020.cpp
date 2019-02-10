// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.

// Example 1:
// Input: "()"
// Output: true

// Example 2:
// Input: "()[]{}"
// Output: true

// Example 3:
// Input: "(]"
// Output: false

// Example 4:
// Input: "([)]"
// Output: false

// Example 5:
// Input: "{[]}"
// Output: true

#include <iostream> 
#include <stack>
#include <string> 
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> test;
        if (s == "") return 1;
        else {
            test.push(s[0]);
            for (int i = 0; i < s.length(); i++) {
                if (s[i] - test.top() == 1 || s[i] - test.top() == 2) {
                    test.pop();
                }
                else test.push(s[i]);
            }
            return test.size() == 1; 
        }
    }
};

int main() {
    Solution s;
    cout << s.isValid("") << endl; 
    cout << s.isValid("()") << endl; 
    cout << s.isValid("()[]{}") << endl; 
    cout << s.isValid("(]") << endl; 
    cout << s.isValid("([)]") << endl; 
    cout << s.isValid("{[]}") << endl; 
    cout << s.isValid("([]") << endl;
    cout << s.isValid("[])") << endl;
    cout << s.isValid("([)") << endl;
    cout << s.isValid("{[}[{}{{({)){[}([]{)}({())[}[}") << endl;
    return 0;
}