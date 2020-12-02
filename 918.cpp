// Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.
// Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)
// Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

#include <vector> 
using namespace std; 

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        if (n == 0) return 0;
        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum += A[i];
        int dp_min[n], dp_max[n];
        memset(dp_min, 0, n * sizeof(int));
        memset(dp_max, 0, n * sizeof(int));
        dp_min[0] = A[0], dp_max[0] = A[0];
        int max_sum = A[0], min_sum = A[0];
        for (int i = 1; i < n; ++i) {
            dp_min[i] = min(dp_min[i - 1] + A[i], A[i]);
            dp_max[i] = max(dp_max[i - 1] + A[i], A[i]);
            if (min_sum > dp_min[i]) min_sum = dp_min[i];
            if (max_sum < dp_max[i]) max_sum = dp_max[i];
        }
        if (sum == min_sum) return max_sum;
        return max(max_sum, sum - min_sum);
    }
};