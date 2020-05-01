// In a given grid, each cell can have one of three values:

// the value 0 representing an empty cell;
// the value 1 representing a fresh orange;
// the value 2 representing a rotten orange.
// Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

#include <vector> 
#include <deque> 
using namespace std; 

class Solution {
public:
    int orangesRotting(vector< vector<int> >& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int rotted[m * n];
        deque<int> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rotted[i * n + j] = 0;
                if (grid[i][j] == 2) {
                    rotted[i * n + j] = 1;
                    q.push_back(i * n + j);
                }
                if (grid[i][j] == 0) rotted[i * n + j] = -1;
            }
        }
        while (!q.empty()) {
            int front = q.front();
            q.pop_front();
            int arr[4] = {-n, -1, 1, n};
            for (int i = 0; i < 4; ++i) {
                if (front + arr[i] < 0 || front + arr[i] >= m * n) continue; 
                if (n != 1 && front % n == n - 1 && arr[i] == 1) continue;
                if (n != 1 && front % n == 0 && arr[i] == -1) continue;
                if (rotted[front + arr[i]] == 0) {
                    q.push_back(front + arr[i]);
                    rotted[front + arr[i]] = rotted[front] + 1;
                } 
            }
        }
        int max = 1;
        for (int i = 0; i < m * n; ++i) {
            if (rotted[i] == 0) return -1;
            max = max >= rotted[i] ? max : rotted[i];
        }
        return max - 1;
    }
};