// Given an array of positive integers arr, calculate the sum of all possible odd-length subarrays.
// A subarray is a contiguous subsequence of the array.
// Return the sum of all odd-length subarrays of arr.


#include <vector> 
using namespace std; 

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        int sum = 0;
        arr.insert(arr.begin(), 0);
        for (int i = 1; i < n + 1; ++i) {
            arr[i] = arr[i - 1] + arr[i];
        }
        for (int i = 0; i < n + 1; ++i) {
            for (int j = i + 1; j < n + 1; ++j) {
                if ((j - i) % 2 == 1) {
                    sum += arr[j] - arr[i];
                }
            }
        }
        return sum;
    }
};

// Solution
// The prefix sum!!