// In a given 2D binary array A, there are two islands.  (An island is a 4-directionally connected group of 1s not connected to any other 1s.)
// Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.
// Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)

#include <vector> 
#include <queue> 
using namespace std; 
class Solution {
public:
    queue< pair<int, int> > q;
    int shortestBridge(vector< vector<int> >& A) {
        int m = A.size();
        if (m == 0) return 0;
        int n = A[0].size();
        if (n == 0) return 0;
        int flag = -1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (A[i][j] == 1) {
                    dfs(A, i, j, flag);
                    flag--;
                }
            }
        }
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int k = 0; k < sz; ++k) {
                pair<int, int> front = q.front();
                q.pop();
                int i = front.first, j = front.second;
                if (bfs(A, i - 1, j, level) || bfs(A, i + 1, j, level) || bfs(A, i, j - 1, level) || bfs(A, i, j + 1, level)) return level;
            }
            level++;
        }
        return 0; // only 1 island
    }
    void dfs(vector< vector<int> >& A, int i, int j, int flag) {
        if (i < 0 || i >= A.size() || j < 0 || j >= A[0].size()) return;
        if (A[i][j] == 0 || A[i][j] == flag) return;
        A[i][j] = flag;
        if (flag == -1) q.push(pair<int, int>(i, j));
        dfs(A, i - 1, j, flag);
        dfs(A, i + 1, j, flag);
        dfs(A, i, j - 1, flag);
        dfs(A, i, j + 1, flag);
    }
    bool bfs(vector< vector<int> >& A, int i, int j, int level) {
        if (i >= 0 && i < A.size() && j >= 0 && j < A[0].size()) {
            if (A[i][j] == 0 || A[i][j] > level){
                A[i][j] = level;
                q.push(pair<int, int>(i, j));
            }
            else if (A[i][j] == -2) return true;
        }
        return false;
    }
};

// Solution
// dfs + bfs
// dfs: locate the islands
// bfs: construct the bridge