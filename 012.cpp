// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

// Example 1:
// Input: 3
// Output: "III"

// Example 2:
// Input: 4
// Output: "IV"

// Example 3:
// Input: 9
// Output: "IX"

// Example 4:
// Input: 58
// Output: "LVIII"
// Explanation: L = 50, V = 5, III = 3.

// Example 5:
// Input: 1994
// Output: "MCMXCIV"
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

#include <iostream> 
using namespace std;

class Solution {
public:
    string _1000ToRoman(int n) {
        string s;
        for (int i = 0; i < n; i++) {
            s.append(1, 'M');
        }
        return s;
    }
    string _100ToRoman(int n) {
        string s;
        if (n < 4) s.append(n, 'C');
        else if (n == 4) s.append("CD");
        else if (n >= 5 && n < 9) {
            s.append(1, 'D');
            s.append(n - 5, 'C');
        }
        else s.append("CM");
        return s;
    }
    string _10ToRoman(int n) {
        string s;
        if (n < 4) s.append(n, 'X');
        else if (n == 4) s.append("XL");
        else if (n >= 5 && n < 9) {
            s.append(1, 'L');
            s.append(n - 5, 'X');
        }
        else s.append("XC");
        return s;
    }
    string _1ToRoman(int n) {
        string s;
        if (n < 4) s.append(n, 'I');
        else if (n == 4) s.append("IV");
        else if (n >= 5 && n < 9) {
            s.append(1, 'V');
            s.append(n - 5, 'I');
        }
        else s.append("IX");
        return s;
    }
    string intToRoman(int num) {
        string str;
        int n1 = num / 1000;
        num %= 1000;
        int n2 = num / 100;
        num %= 100;
        int n3 = num / 10;
        num %= 10;
        int n4 = num;
        str.append(_1000ToRoman(n1));
        str.append(_100ToRoman(n2));
        str.append(_10ToRoman(n3));
        str.append(_1ToRoman(n4));
        return str;
    }
};