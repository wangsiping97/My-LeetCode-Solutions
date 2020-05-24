// Determine the largest rectangle of 1s in a binary matrix (a binary matrix only contains 0 and 1), return the area.

// Assumptions
// The given matrix is not null and has size of M * N, M >= 0 and N >= 0

#include <iostream> 
#include <vector> 
#include <stack> 
#include <cstdlib> 
using namespace std; 

class Solution {
 public:
  int largest(vector< vector<int> > matrix) {
    // write your solution here
    if (matrix.empty() || matrix[0].empty()) return 0;
    int ans;
    int m = matrix.size(), n = matrix[0].size();
    int** height = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; ++i) {
        height[i] = (int*)malloc((n + 1) * sizeof(int));
        memset(height[i], -1, n * sizeof(int));
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (i == 0) height[i][j] = matrix[i][j];
          else height[i][j] = matrix[i][j] == 0 ? 0 : height[i - 1][j] + 1;
        }
        int temp = largestHist(height[i], n);
        if (temp > ans) ans = temp;
    }
    return ans;
  }
  int largestHist(int* height, int n) {
      stack<int> s; 
      int res = 0;
      for (int i = 0; i <= n; ++i) {
        if (s.empty() || height[i] >= height[s.top()]) {
            s.push(i);
        }
        else {
            while(!s.empty() && height[s.top()] > height[i]) {
                int id = s.top(); s.pop();
                int area = height[id] * (s.empty() ? i : i - s.top() - 1); // IMPORTANT
                res = max(res, area);
            }
            s.push(i);
        }
      }
      return res;
  }
};


int main() {
    Solution s;
    int arr[5] = {0,2,1,2,-1};
    cout << s.largestHist(arr, 4);
}
