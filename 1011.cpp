// A conveyor belt has packages that must be shipped from one port to another within D days.
// The i-th package on the conveyor belt has a weight of weights[i].  Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within D days.
// Note that the cargo must be shipped in the order given.

#include <vector> 
#include <cmath> 
using namespace std; 

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int n = weights.size();
        if (n == 0) return 0;
        int sum = 0, max_weight = weights[0];
        for (int i = 0; i < n; ++i) {
            sum += weights[i];
            max_weight = max_weight > weights[i] ? max_weight : weights[i];
        }
        int low = max_weight, high = sum, ans = sum;
        while (low < high) {
            int mid = low + (high - low) / 2; // this capacity
            int start = 0, d = 0;
            while (start < n) {
                int temp = 0; // total weight in a day
                while (start < n && temp + weights[start] <= mid) {
                    temp += weights[start];
                    start ++;
                }
                d++;
            }
            if (d <= D) {
                ans = mid < ans ? mid : ans;
                high = mid;
            }
            else low = mid + 1;
        }
        return ans;
    }
};

// Solution
// Binary Search --> answer, from max_weight to sum 
// 模拟