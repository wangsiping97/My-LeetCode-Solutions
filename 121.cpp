// Say you have an array for which the ith element is the price of a given stock on day i.
// If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
// Note that you cannot sell a stock before you buy one.

#include <vector> 
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = prices.size();
        if (l == 0) return 0;
        int ans = 0;
        int localmin = prices[0];
        for (int i = 0; i < l; ++i) {
            localmin = prices[i] < localmin ? prices[i] : localmin;
            ans = prices[i] - localmin > ans ? prices[i] - localmin : ans;
        }
        return ans;
    }
};

// Solution:
// The core of this problem is to find the largest difference in the array (latter - former)
// Dynamic Programming: f(i + 1) = max(f(i), prices[i] - min(prices[0:i]))