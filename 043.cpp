// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

// Example 1:
// Input: num1 = "2", num2 = "3"
// Output: "6"

// Example 2:
// Input: num1 = "123", num2 = "456"
// Output: "56088"

// Note:
// The length of both num1 and num2 is < 110.
// Both num1 and num2 contain only digits 0-9.
// Both num1 and num2 do not contain any leading zero, except the number 0 itself.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.

#include <iostream> 
#include <string> 
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        int l1 = num1.length();
        int l2 = num2.length();
        if (l1 == 0 || l2 == 0) return res;
        vector<int> temp(l1 + l2 - 1, 0);
        string a = num1;
        int i = 0;
        while(num2.length()) {
            a = num1;
            while(!a.empty()) {
                temp[i] += (a.back() - '0') * (num2.back() - '0');
                cout << temp[i] << " ";
                i++;
                a.pop_back();
            }
            cout << endl;
            num2.pop_back();
            i -= l1;
            i++;
        }
        int up = 0;
        for (int j = 0; j < temp.size(); j++) {
            temp[j] += up;
            up = temp[j] / 10;
            temp[j] %= 10;
        } 
        if (up > 0) temp.push_back(up);
        while (!temp.empty() && temp.back() == 0) {
            temp.pop_back();
        }
        if (temp.empty()) temp.push_back(0);
        for (int j = temp.size() - 1; j >= 0; j--) {
            res.push_back(temp[j] + '0');
        }
        return res;
    }
};

int main() {
    string num1 = "1111111111111111111111";
    string num2 = "0";
    Solution s;
    cout << s.multiply(num1, num2);
}