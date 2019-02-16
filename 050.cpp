// Implement pow(x, n), which calculates x raised to the power n (xn).

// Example 1:
// Input: 2.00000, 10
// Output: 1024.00000

// Example 2:
// Input: 2.10000, 3
// Output: 9.26100

// Example 3:
// Input: 2.00000, -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25

// Note:
// -100.0 < x < 100.0
// n is a 32-bit signed integer, within the range [−231, 231 − 1]

#include <iostream> 
#include <cmath>
using namespace std;

class Solution {
public:
    double middle(double x, int m) {
        double middle = x * x;
        for (int i = 1; i < m; i++) {
            middle = middle * middle;
        }
        return m == 0 ? x : middle;
    }

    double myPow(double x, int n) {
        if (n == 0) return 1;
        double ans = 1;
        int n_ =  n > 0 ? n - 1 : -1 - n, count = 0;
        while (n_) {
            if (n_ % 2 == 1) {
                ans *= middle(x, count);
            }
            n_ /= 2;
            count++;
        }
        return n > 0 ? x * ans : 1 / (x *ans);
    }
};

int main() {
    Solution s;
    cout << s.myPow(2.00000, 10) << endl;
    cout << s.myPow(2.10000, 3) << endl;
    cout << s.myPow(2.00000, -2) << endl;
    cout << s.myPow(1, -2147483648) << endl;
    return 0;
}