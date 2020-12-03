// You are given an even number of people num_people that stand around a circle and each person shakes hands with someone else, so that there are num_people / 2 handshakes total.
// Return the number of ways these handshakes could occur such that none of the handshakes cross.
// Since this number could be very big, return the answer mod 10^9 + 7

#include <iostream> 
using namespace std; 

class Solution {
public:
    int numberOfWays(int num_people) {
        long long dp[num_people + 1];
        memset(dp, 0, (num_people + 1) * sizeof(long long));
        dp[0] = 1; dp[2] = 1;
        for (int i = 4; i < num_people + 1; i += 2) {
            for (int j = 0; j <= i - 2; j += 2) {
                dp[i] += dp[j] * dp[i - 2 - j];
                dp[i] %= 1000000007;
            }
        }
        return dp[num_people];
    }
};

// Solution
// dp[i] := the number of ways with i persons
// dp[i] = dp[0] * dp[n - 2] + dp[2] * dp[n - 4] + .. + dp[n - 2] * dp[0]