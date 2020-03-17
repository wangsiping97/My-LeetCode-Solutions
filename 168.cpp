// Given a positive integer, return its corresponding column title as appear in an Excel sheet.

// For example:
//     1 -> A
//     2 -> B
//     3 -> C
//     ...
//     26 -> Z
//     27 -> AA
//     28 -> AB 
//     ...

#include <string> 
using namespace std; 

class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while (n) {
            if (n % 26 == 0) {
                ans = "Z" + ans;
                n = n / 26 - 1;
            }
            else {
                string s(1, n % 26 -1 + 'A');
                ans = s + ans;
                n /= 26;
            }
        }
        return ans;
    }
};

 // Solution
 // 1. n % 26 == 0
 // 2. n % 26 != 0