// Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.
// Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.
// Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

// Note:
// The order of returned grid coordinates does not matter.
// Both m and n are less than 150.

#include <vector> 
#include <deque> 
#include <cstdlib> 
using namespace std; 

class Solution {
public:
    vector< vector<int> > pacificAtlantic(vector< vector<int> >& matrix) {
        vector< vector<int> > ans; 
        int m = matrix.size();
        if (m == 0) return ans; 
        int n = matrix[0].size();
        int* can1 = (int*)malloc((m * n) * sizeof(int));
        memset(can1, 0, m * n * sizeof(int));
        int* can2 = (int*)malloc((m * n) * sizeof(int));
        memset(can2, 0, m * n * sizeof(int));
        deque<int> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    q.push_back(i * n + j);
                    can1[i * n + j] = 1;
                }
            }
        }
        while (!q.empty()) {
            int front = q.front();
            q.pop_front();
            int i = front / n; 
            int j = front % n;
            for (int ii = i - 1; ii <= i + 1; ii += 2) {
                if (ii < 0 || ii == m) continue; 
                if (matrix[ii][j] >= matrix[i][j]) 
                    if (can1[ii * n + j] == 0) {
                        can1[ii * n + j] = 1;
                        q.push_back(ii * n + j);
                    }
            }
            for (int jj = j - 1; jj <= j + 1; jj += 2) {
                if (jj < 0 || jj == n) continue; 
                if (matrix[i][jj] >= matrix[i][j]) {
                    if (can1[i * n + jj] == 0) {
                        can1[i * n + jj] = 1;
                        q.push_back(i * n + jj);
                    }
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == m - 1 || j == n - 1) {
                    q.push_back(i * n + j);
                    can2[i * n + j] = 1;
                }
            }
        }
        while (!q.empty()) {
            int front = q.front();
            q.pop_front();
            int i = front / n; 
            int j = front % n;
            for (int ii = i - 1; ii <= i + 1; ii += 2) {
                if (ii < 0 || ii == m) continue; 
                if (matrix[ii][j] >= matrix[i][j]) 
                    if (can2[ii * n + j] == 0) {
                        can2[ii * n + j] = 1;
                        q.push_back(ii * n + j);
                    }
            }
            for (int jj = j - 1; jj <= j + 1; jj += 2) {
                if (jj < 0 || jj == n) continue; 
                if (matrix[i][jj] >= matrix[i][j]) {
                    if (can2[i * n + jj] == 0) {
                        can2[i * n + jj] = 1;
                        q.push_back(i * n + jj);
                    }
                }
            }
        }
        for (int k = 0; k < m * n; ++k) {
            if (can1[k] == 1 && can2[k] == 1) {
                int i = k / n;
                int j = k % n;
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(j);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};