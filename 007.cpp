// Given a 32-bit signed integer, reverse digits of an integer.

// Example 1:
// Input: 123
// Output: 321

// Example 2:
// Input: -123
// Output: -321

// Example 3:
// Input: 120
// Output: 21

// Note:
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

#include <iostream> 
#include <cstdint>
#include <limits>
using namespace std; 

class Solution {
public: 
    int reverse(int x) {
        int rx = 0;
        int temp;
        while (x >= 10 || x <= -10) {
            rx += x % 10;
            x /= 10;
            if (rx > INT32_MAX / 10 || (rx == INT32_MAX / 10 && x > 7)) return 0;
            else if (rx < INT32_MIN / 10 || (rx == INT32_MAX / 10 && x > 8)) return 0;
            else {
                rx *= 10;
            }
        }
        return rx + x;
    }
};

int main() {
    Solution s;
    cout << s.reverse(123) << endl;
    cout << s.reverse(-123) << endl;
    cout << s.reverse(120) << endl;
    cout << s.reverse(1534236469) << endl;
    return 0;
}