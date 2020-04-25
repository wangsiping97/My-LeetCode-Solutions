// Additive number is a string whose digits can form additive sequence.
// A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
// Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.
// Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

#include <string> 
#include <iostream> 
using namespace std; 

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        if (n < 3) return false;
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                string s1 = num.substr(0, i);
                string s2 = num.substr(i, j - i);
                if ((s1[0] == '0' && i > 1) || (s2[0] == '0' && j - i > 1)) continue; 
                string s3 = num.substr(j);
                if (s3.length() == 0) continue;
                if (dfs(s1, s2, s3)) return true;
            }
        }
        return false;
    }
    bool dfs (string s1, string s2, string s3) {
        string sum = add(s1, s2);
        // string sum = to_string(atoi(s1.data()) + atoi(s2.data()));
        int l = sum.length();
        if (l > s3.length()) return false;
        if (l == s3.length()) return sum == s3;
        string part = s3.substr(0, l);
        if (part != sum) return false;
        if (dfs(s2, part, s3.substr(l))) return true;
        return false;
    }
    string add(string s1, string s2) {
        string ans = "";
        int up = 0;
        int i = 0, l1 = s1.length(), l2 = s2.length();
        while (i < l1 && i < l2) {
            int temp = s1[l1 - 1 - i] - '0' + s2[l2 - 1 - i] - '0' + up;
            if (temp >= 10) {
                up = 1;
                temp -= 10;
            }
            else up = 0;
            ans = to_string(temp) + ans;
            i++;
        }
        while (i < l1) {
            int temp = s1[l1 - 1 - i] - '0' + up;
            if (temp >= 10) {
                up = 1;
                temp -= 10;
            }
            else up = 0;
            ans = to_string(temp) + ans;
            i++;
        }
        while (i < l2) {
            int temp = s2[l2 - 1 - i] - '0' + up;
            if (temp >= 10) {
                up = 1;
                temp -= 10;
            }
            else up = 0;
            ans = to_string(temp) + ans;
            i++;
        }
        if (up == 1) ans = "1" + ans;
        return ans;
    }
};

int main() {
    Solution s;
    // cout << s.add("1", "99") << endl;
    cout << s.isAdditiveNumber("199100199") << endl;
}