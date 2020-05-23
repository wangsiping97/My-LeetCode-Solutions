// Given an integer array A representing a forest, such that, A[i] means the parent index of index i, if A[i] == -1, it means index i is a root.
// Determine what is the depth of the forest, the depth of the forest is the maximum depth of the trees in the forest.

#include <vector> 
#include <deque> 
using namespace std; 

class Solution {
 public:
  int depth(vector<int> forest) {
    // write your solution here
    int n = forest.size();
    if (n == 0) return 0; 
    int checked[n];
    memset(checked, 0, n * sizeof(int));
    deque<int> q;
    for (int i = 0; i < n; ++i) {
        if (forest[i] == -1) {
            q.push_back(i);
            checked[i] = 1;
        }
    }
    int count = 0;
    while (!q.empty()) {
        count++;
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            int top = q.front();
            q.pop_front();
            for (int j = 0; j < n; ++j) {
                if (forest[j] == top) {
                    checked[j] = 1;
                    q.push_back(j);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (checked[i] == 0) return -1;
    }
    return count;
  }
};
