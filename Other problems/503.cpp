// You are given a m x n 2D grid initialized with these three possible values.

// -1 - A wall or an obstacle.
// 0 - A gate.
// INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647

// Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

#include <vector> 
#include <deque> 
using namespace std; 

class Solution {
public:
    vector< vector<int> > wallsAndGates(vector< vector<int> > rooms) {
        // write your solution here
        int m = rooms.size();
        if (m == 0) return rooms; 
        int n = rooms[0].size();
        if (n == 0) return rooms;
        deque<int> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0) q.push_back(i * n + j);
            }
        }
        while (!q.empty()) {
            int sz = q.size();
            for (int k = 0; k < sz; ++k) {
                int temp = q.front();
                q.pop_front();
                int i = temp / n;
                int j = temp % n;
                for (int ii = i - 1; ii <= i + 1; ii += 2) {
                    if (ii < 0 || ii >= m) continue;
                    if (rooms[ii][j] == -1) continue; 
                    if (rooms[ii][j] <= rooms[i][j] + 1) continue; 
                    rooms[ii][j] = rooms[i][j] + 1;
                    q.push_back(ii * n + j);
                }
                for (int jj = j - 1; jj <= j + 1; jj += 2) {
                    if (jj < 0 || jj >= n) continue;
                    if (rooms[i][jj] == -1) continue; 
                    if (rooms[i][jj] <= rooms[i][j] + 1) continue; 
                    rooms[i][jj] = rooms[i][j] + 1;
                    q.push_back(i * n + jj);
                }
            }
        }
        return rooms;
    }
};
