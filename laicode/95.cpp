// We have a list of piles of stones, each pile of stones has a certain weight, represented by an array of integers. In each move, we can merge two adjacent piles into one larger pile, the cost is the sum of the weights of the two piles. We merge the piles of stones until we have only one pile left. Determine the minimum total cost.

#include <iostream> 
#include <vector> 
#include <cstdlib> 
using namespace std; 

class Solution {
 public:
  int minCost(vector<int> stones) {
    // write your solution here
    int n = stones.size();
    if (n <= 1) return 0; 
    int** dp = (int**)malloc(n * sizeof(int*));
    int** weight = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        dp[i] = (int*)malloc(n * sizeof(int));
        weight[i] = (int*)malloc(n * sizeof(int));
        memset(dp[i], 0, n * sizeof(int));
        memset(weight[i], 0, n * sizeof(int));
    }
    
    for (int diff = 0; diff < n; ++diff) {
        for (int i = 0; i + diff < n; ++i) {
            int j = i + diff;
            if (diff == 0) {
                dp[i][j] = 0;
                weight[i][j] = stones[i];
            }
            else if (diff == 1) {
                dp[i][j] = stones[i] + stones[j];
                weight[i][j] = stones[i] + stones[j];
            }
            else {
                weight[i][j] = weight[i][j - 1] + stones[j];
                int min = INT_MAX; 
                for (int k = i; k < j; ++k) {
                    int temp = dp[i][k] + dp[k + 1][j] + weight[i][k] + weight[k + 1][j];
                    if (temp < min) min = temp;
                }
                dp[i][j] = min;
            }
        }
    }
    return dp[0][n - 1];
  }
};