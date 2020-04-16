// Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

// Formally the function should:
// Return true if there exists i, j, k
// such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
// Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

#include <vector> 
using namespace std; 

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        int min = nums[0];
        int aj;
        int i;
        for (i = 1; i < n; ++i) {
            if (nums[i] > min) {
                aj = nums[i];
                break;
            }
            if (nums[i] < min) min = nums[i];
        }
        if (i == n) return false;
        for (int j = i; j < n; ++j) {
            if (nums[j] > aj) return true;
            if (nums[j] > min && nums[j] < aj)
                aj = nums[j];
            if (nums[j] < min) min = nums[j];
        }
        return false;
    }
};