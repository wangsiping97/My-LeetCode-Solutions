// Implement int sqrt(int x).
// Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
// Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

#include <iostream> 

class Solution {
public:
    int mySqrt(int x) {
        if (46340 * 46340 <= x) return 46340;
        int res = std::min(x, 46340);
        while (res * res > x) {
            res = (res + x / res) / 2;
        } 
        return res;
    }
};