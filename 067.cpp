// Given two binary strings, return their sum (also a binary string).
// The input strings are both non-empty and contains only characters 1 or 0.
// Example 1:
// Input: a = "11", b = "1"
// Output: "100"
// Example 2:
// Input: a = "1010", b = "1011"
// Output: "10101"

#include <string> 
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.length();
        int lb = b.length();
        int l;
        if (la >= lb) {
            b.insert(0, la - lb, '0');
            l = la;
        }
        else {
            a.insert(0, lb - la, '0');
            l = lb;
        }
        int in = 0;
        for (int i = l - 1; i >= 0; --i) {
            a[i] += b[i] - '0' + in;
            in = 0;
            if (a[i] >= '2') {
                in = 1;
                a[i] -= 2;
            }
        }
        if (in > 0) {
            a.insert(0, 1, '1');
        }
        return a;
    }
};