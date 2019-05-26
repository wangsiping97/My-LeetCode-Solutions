// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

// Example 1:

// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true
// Example 2:

// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false

#include <iostream>
using namespace std;
bool isInterleave(char* s1, char* s2, char* s3) 
{
    int n1, n2, m;
    n1 = strlen(s1);
    n2 = strlen(s2);
    m = n1 + n2;
    if (strlen(s3) != n1 + n2) return false;
    bool f[m + 1][n1 + 1];
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= i; j++)
            if (j <= n1)
               f[i][j] = false;
    f[0][0] = true;
    
    for (int i = 0; i <= m - 1; i++)
        for (int j = 0; j <= i; j++)
            if (j <= n1)
                if (f[i][j]) 
                {
                    if (j < n1)
                        if (s1[j] == s3[i]) f[i + 1][j + 1] |= f[i][j];
                    if (i - j < n2)
                        if (s2[i - j] == s3[i]) f[i + 1][j] |= f[i][j];
                }
    bool ans = false;
    for (int j = 0; j <= n1; j++)
        ans |= f[m][j];
    return ans;
}
