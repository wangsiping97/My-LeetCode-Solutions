// Given a wooden stick of length n units. The stick is labelled from 0 to n.
// Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.
// You should perform the cuts in order, you can change the order of the cuts as you wish.
// The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.
// Return the minimum total cost of the cuts.

#include <vector> 
using namespace std; 

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        if (n == 0) return 0;
        int sz = cuts.size();
        if (sz == 0) return 0;
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sz += 2;
        int dp[sz][sz];
        memset(dp, 0, sizeof(dp));
        for (int dif = 0; dif < sz; ++dif) {
            for (int i = 0; i + dif < sz; ++i) {
                dp[i][i + dif] = (dif > 1) ? INT_MAX : 0;
                for (int k = i + 1; k < i + dif; ++k) {
                    dp[i][i + dif] = min(dp[i][i + dif], cuts[i + dif] - cuts[i] + dp[i][k] + dp[k][i + dif]);
                }
            }
        }
        return dp[0][sz - 1];
    }
};

// Solution
// dp[i][j] := minCost between cuts[i] and cuts[j]
// dp[i][j] = min{cuts[j] - cuts[i] + dp[i][k] + dp[k][j]} for k in [i + 1, j - 1]