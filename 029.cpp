// Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
// Return the quotient after dividing dividend by divisor.
// The integer division should truncate toward zero.

// Example 1:
// Input: dividend = 10, divisor = 3
// Output: 3

// Example 2:
// Input: dividend = 7, divisor = -3
// Output: -2

// Note:
// Both dividend and divisor will be 32-bit signed integers.
// The divisor will never be 0.
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.

#include <iostream> 
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == -2147483648 && divisor == 1) return -2147483648;

        unsigned int ans = 0;
        unsigned int dividend_ = dividend < 0 ? -(unsigned int)dividend : dividend;
        unsigned int divisor_ = divisor < 0 ? -(unsigned int)divisor : divisor;
        unsigned int n = 1, d = divisor_;

        while ((d < 2147483648) && (d << 1) <= dividend_) {
            d = d << 1;
            n = n << 1;
        }
        if (n != 1) {
        dividend_ -= d;
        ans += n;
        }
        while (dividend_ >= divisor_) {
            while (d > dividend_) {
                d = d >> 1;
                n = n >> 1;
            }
            dividend_ -= d;
            ans += n;
        }
        if (ans == 2147483648) ans = 2147483647;

        return (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0) ? -ans : ans;
    }
};