// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

// Example 1:
// Input: "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()"

// Example 2:
// Input: ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()"

#include <string> 
#include <stack>
#include <iostream> 
using namespace std; 

class Solution {
public:
    int longestValidParentheses(string s) {
        int l = s.length();
        if (l < 2) return 0;
        int arr[2 * l + 1];
        for (int i = 0; i < 2 * l + 1; ++i)
            arr[i] = -2;
        int sum = l;
        int ans = 0;
        arr[l] = -1;
        for (int i = 0; i < l; ++i) {
            if (s[i] == '(') {
                sum += 1;
                arr[sum] = i;
            }
            else {
                sum -= 1;
                if (arr[sum] == -2) arr[sum] = i;
                else {
                    ans = max(ans,i - arr[sum]);
                }
            }
        }
        for (int i = 0; i < 2 * l + 1; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.longestValidParentheses("()(())");
}

// Solution 
// O(N): 从左到右扫一遍，对每个')'节点，向左找到最远的【能看到的】'('节点