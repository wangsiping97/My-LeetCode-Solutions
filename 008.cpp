// Implement atoi which converts a string to an integer.

// The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
// The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
// If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
// If no valid conversion could be performed, a zero value is returned.

// Note:
// Only the space character ' ' is considered as whitespace character.
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.

// Example 1:
// Input: "42"
// Output: 42

// Example 2:
// Input: "   -42"
// Output: -42
// Explanation: The first non-whitespace character is '-', which is the minus sign.
//              Then take as many numerical digits as possible, which gets 42.

// Example 3:
// Input: "4193 with words"
// Output: 4193
// Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.

// Example 4:
// Input: "words and 987"
// Output: 0
// Explanation: The first non-whitespace character is 'w', which is not a numerical 
//              digit or a +/- sign. Therefore no valid conversion could be performed.

// Example 5:
// Input: "-91283472332"
// Output: -2147483648
// Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
//              Thefore INT_MIN (−231) is returned.

#include <iostream> 
using namespace std;

class Solution {
public:
    bool isNumber(char c) {
        return c >= '0' && c <= '9';
    }
    int myAtoi(string str) {
        if (str.length() == 0) return 0;
        int l = 0, i = 0;
        while (str[i] == ' ') {
            l++;
            i++;
        }
        l = str.length() - l;
        str = str.substr(i, l);
        if (str[0] == '+') {
            if (l > 1 && !isNumber(str[1])) return 0;
            else return myAtoi(str.substr(1, l - 1));
        }
        else if (str[0] == '-') {
            if (l > 1 && !isNumber(str[1])) return 0;
            else {
                str = str.substr(1, l - 1);
                if (str.length() == 0) return 0;
                int ans = 0;
                int ll = 0, i = 0, j = 0;
                while (str[i] == '0') {
                    i++;
                    j++;
                }
                while (isNumber(str[i])) {
                    ll++;
                    i++;
                }
                if (ll > 10 || (ll == 10 && str >= "2147483648")) return -2147483648;
            else {
                for (int i = j; i < j + ll - 1; i++) {
                    ans += str[i] - '0';
                    ans *= 10;
                }
                ans += str[j + ll - 1] - '0';
                return -ans;
            }
            }
        }
        else if (!isNumber(str[0])) return 0;
        else {
            int ans = 0;
            int ll = 0, i = 0, j = 0;
            while (str[i] == '0') {
                i++;
                j++;
            }
            while (isNumber(str[i])) {
                ll++;
                i++;
            }
            if (ll > 10 || (ll == 10 && str >= "2147483647")) return 2147483647;
            else {
                for (int i = j; i < j + ll - 1; i++) {
                    ans += str[i] - '0';
                    ans *= 10;
                }
                ans += str[j + ll - 1] - '0';
                return ans;
            }
        }
    }
};

int main() {
    Solution s;
    cout << s.myAtoi("42") << endl;
    cout << s.myAtoi("-42") << endl;
    cout << s.myAtoi("4193 with words") << endl;
    cout << s.myAtoi("words and 987") << endl;
    cout << s.myAtoi("-91283472332") << endl;
    cout << s.myAtoi("  0000000000012345678") << endl;
    return 0;
}