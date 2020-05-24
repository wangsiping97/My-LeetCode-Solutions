// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

#include <vector> 
#include <stack> 
using namespace std; 

class Solution {
public:
    int maximalRectangle(vector <vector<char> >& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0; 
        int m = matrix.size(), n = matrix[0].size();
        vector< vector<int> > heights(m);
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0) heights[i].push_back(matrix[i][j] - '0');
                else if (matrix[i][j] == '0') heights[i].push_back(0);
                else heights[i].push_back(heights[i - 1][j] + 1);
            }
            int temp = maximalHist(heights[i]);
            if (temp > ans) ans = temp;
        }
        return ans;
    }
    int maximalHist(vector<int>& arr) {
        int max = 0;
        arr.push_back(-1);
        int n = arr.size();
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            if (s.empty() || arr[s.top()] <= arr[i]) s.push(i);
            else {
                while (!s.empty() && arr[s.top()] > arr[i]) {
                    int top = s.top();
                    s.pop();
                    int temp = arr[top] * (s.empty() ? i : i - (s.top() + 1));
                    if (temp > max) max = temp;
                }
                s.push(i);
            }
        }
        return max;
    }
};