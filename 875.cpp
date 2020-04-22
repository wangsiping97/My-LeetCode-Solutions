// Koko loves to eat bananas.  There are N piles of bananas, the i-th pile has piles[i] bananas.  The guards have gone and will come back in H hours.
// Koko can decide her bananas-per-hour eating speed of K.  Each hour, she chooses some pile of bananas, and eats K bananas from that pile.  If the pile has less than K bananas, she eats all of them instead, and won't eat any more bananas during this hour.
// Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards come back.
// Return the minimum integer K such that she can eat all the bananas within H hours.

 #include <vector> 
 #include <cmath> 
 using namespace std; 

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int n = piles.size();
        if (n == 0) return 0;
        int max = piles[0];
        for (int i = 0; i < n; ++i) {
            max = max > piles[i] ? max : piles[i];
        }
        int low = 1, high = max;
        int ans = high;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int h = 0;
            for (int i = 0; i < n; ++i) {
                h += ceil((float)piles[i] / mid);
            }
            if (h <= H) {
                high = mid;
                ans = ans < mid ? ans : mid;
            }
            else low = mid + 1;
        }
        return ans;
    }
};