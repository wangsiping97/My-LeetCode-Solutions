// Given a string which contains only lowercase letters, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

#include <string> 
#include <stack> 
using namespace std; 

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int l = s.length();
        if (l == 0) return "";
        int arr[128];
        int isIn[128];
        memset(arr, 0, 128 * 4);
        memset(isIn, 0, 128 * 4);
        for (int i = 0; i < l; ++i) {
            arr[s[i]]++;
        }
        stack<char> st;
        st.push(s[0]);
        arr[s[0]]--;
        isIn[s[0]] = 1;
        for (int j = 1; j < l; ++j) {
            if (isIn[s[j]] == 1) {
                arr[s[j]]--;
                continue;
            }
            while (!st.empty() && s[j] < st.top() && arr[st.top()] > 0) {
                isIn[st.top()] = 0;
                st.pop();
            }
            st.push(s[j]);
            isIn[s[j]] = 1;
            arr[s[j]]--;
        }
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

// Solution
// 1. Count out how many times each character appears in the string -- using arr[128]
// 2. Greedy with stack: 
// for char in string: 
// if char is already in the stack: continue
// while char < top && top still appears backwards: pop the top
// push the char