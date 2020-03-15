// Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

// Note:
// The length of both num1 and num2 is < 5100.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.

#include <string> 
using namespace std; 

class Solution {
public:
    string addStrings(string num1, string num2) {
        int l1 = num1.length(), l2 = num2.length();
        // make l1 >= l2
        if (l1 < l2) {
            num1.swap(num2); // string.swap
            int temp = l1;
            l1 = l2;
            l2 = temp;
        }
        string ans = "";
        ans.resize(l1);
        int p = 0;
        for (int i = 0; i < l2; ++i) {
            ans[l1 - 1 - i] = p + num1[l1 - 1 - i] + num2[l2 - 1 - i] - '0';
            if (ans[l1 - 1 - i] > '9') {
                ans[l1 - 1 - i] -= 10;
                p = 1;
            }
            else p = 0;
        }
        for (int j = l2; j < l1; ++j) {
            ans[l1 - 1 - j] = p + num1[l1 - 1 - j];
            if (ans[l1 - 1 - j] > '9') {
                ans[l1 - 1 - j] -= 10;
                p = 1;
            }
            else p = 0;
        }
        if (p == 1) ans = "1" + ans;
        return ans;
    }
};

// Solution
// kind of like brute force, but O(n)