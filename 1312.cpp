// Given a string s. In one step you can insert any character at any index of the string.
// Return the minimum number of steps to make s palindrome.
// A Palindrome String is one that reads the same backward as well as forward.

#include <string> 
#include <iostream> 
using namespace std; 

class Solution {
public:
    int minInsertions(string s) {
        int l = s.length();
        if (l == 0) return 0;
        int dp[l][l];
        for (int i = 0; i < l; ++i)
            memset(dp[i], 0, l * 4);
        for (int k = 1; k < l; ++k) {
            for (int i = 0; i + k < l; ++i) {
                if (k == 1) {
                    if (s[i] == s[i + k]) dp[i][i + k] = 0;
                    else dp[i][i + k] = 1;
                }
                else {
                    if (s[i] == s[i + k]) dp[i][i + k] = dp[i + 1][i + k - 1];
                    else dp[i][i + k] = min(min(dp[i][i + k - 1] + 1, dp[i + 1][i + k] + 1), dp[i + 1][i + k - 1] + 2);
                }
            }
        }
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < l; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[0][l - 1];
    }
};

int main() {
    Solution ss;
    cout << ss.minInsertions("yuyabzkqa");
    return 0;
}