// Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
// Return the length of the longest (contiguous) subarray that contains only 1s. 

#include <vector> 
using namespace std; 

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size();
        if (n <= K) return n;
        int left = 0, right = 0;
        int count = 0;
        int ans = 0;
        while (right < n) {
            if (A[right] == 0) count++;
            while (count == K + 1) {
                if (A[left] == 0) count--;
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};

// Solution
// Sliding window