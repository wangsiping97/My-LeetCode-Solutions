// Given two strings of alphanumeric characters, determine the minimum number of Replace, Delete, and Insert operations needed to transform one string into the other.

// Assumptions
// Both strings are not null

#include <iostream> 
#include <string> 
#include <cstdlib> 
using namespace std; 
class Solution {
 public:
  int editDistance(string one, string two) {
    // write your solution here
    int n = one.length();
    int m = two.length();
    if (n == 0) return m;
    if (m == 0) return n;
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; ++i) 
        memset(dp[i], 0, m * sizeof(int));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
            else if (one[i - 1] == two[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else {
                int t1 = dp[i - 1][j - 1], t2 = dp[i - 1][j], t3 = dp[i][j - 1];
                if (t1 <= t2 && t1 <= t3) dp[i][j] = t1 + 1;
                else if (t2 <= t1 && t2 <= t3) dp[i][j] = t2 + 1;
                else dp[i][j] = t3 + 1;
            }
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n][m];
  }
};

int main() {
    Solution s;
    cout << s.editDistance("ab", "dbbabc");
}