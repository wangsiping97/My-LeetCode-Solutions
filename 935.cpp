// The chess knight has a unique movement, it may move two squares vertically and one square horizontally, or two squares horizontally and one square vertically (with both forming the shape of an L). The possible movements of chess knight are shown in this diagaram:
// We have a chess knight and a phone pad as shown below, the knight can only stand on a numeric cell (i.e. blue cell).
// Given an integer n, return how many distinct phone numbers of length n we can dial.
// You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 jumps to dial a number of length n. All jumps should be valid knight jumps.
// As the answer may be very large, return the answer modulo 10^9 + 7.

#include <unordered_map> 
#include <vector> 
using namespace std; 

class Solution {
public:
    int knightDialer(int n) {
        long long ans = 0;
        long long dp[10][n + 1];
        memset(dp, 0, sizeof(dp));
        unordered_map< int, vector<int> > map;
        map[0] = {4, 6};
        map[1] = {6, 8};
        map[2] = {9, 7};
        map[3] = {4, 8};
        map[4] = {0, 3, 9};
        map[5] = {};
        map[6] = {0, 1, 7};
        map[7] = {2, 6};
        map[8] = {1, 3};
        map[9] = {2, 4};
        for (int j = 1; j < n + 1; ++j) {
            for (int i = 0; i < 10; ++i) {
                if (j == 1) dp[i][j] = 1;
                else {
                    for (int val : map[i]) dp[i][j] += dp[val][j - 1];
                    dp[i][j] %= 1000000007;
                }
            }
        }
        for (int i = 0; i < 10; ++i) ans += dp[i][n];
        return ans % 1000000007;
    }
};

// Solution
// dp[i][j] := num of different phone numbers (length = j) starting from i
// {a, b, ...} are the possible next steps from i
// dp[i][j] = sum{dp[a][j - 1] + dp[b][j - 1] + ...}