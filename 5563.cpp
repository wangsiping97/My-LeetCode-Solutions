// You have an inventory of different colored balls, and there is a customer that wants orders balls of any color.
// The customer weirdly values the colored balls. Each colored ball's value is the number of balls of that color you currently have in your inventory. For example, if you own 6 yellow balls, the customer would pay 6 for the first yellow ball. After the transaction, there are only 5 yellow balls left, so the next yellow ball is then valued at 5 (i.e., the value of the balls decreases as you sell more to the customer).
// You are given an integer array, inventory, where inventory[i] represents the number of balls of the ith color that you initially own. You are also given an integer orders, which represents the total number of balls that the customer wants. You can sell the balls in any order.
// Return the maximum total value that you can attain after selling orders colored balls. As the answer may be too large, return it modulo 109 + 7.

#include <vector> 
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        long long int ans = 0;
        sort(inventory.begin(), inventory.end());
        int n = inventory.size();
        int minprice = BinarySearch(inventory, orders);
        for (int i = 0; i < n; ++i) {
            if (inventory[i] > minprice) {
                ans += ((long long)inventory[i] + minprice + 1) * (inventory[i] - minprice) / 2;
                orders -= (inventory[i] - minprice);
            }
        }
        ans += (long long)minprice * orders;
        return (int)(ans % 1000000007);
    }
    // search for the lowest price. i.e., finally [...., price, price, ...price]
    int BinarySearch(vector<int>& inventory, int orders) {
        int left = 0, right = inventory[inventory.size() - 1], mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            long long tmp = 0;
            for (int i = 0; i < inventory.size(); ++i) {
                if (inventory[i] > mid) {
                    tmp += ((long long)inventory[i] - mid);
                }
            }
            if (tmp < orders) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};