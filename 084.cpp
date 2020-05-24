// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

#include <vector> 
#include <stack> 
using namespace std; 

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        heights.push_back(-1);
        int n = heights.size();
        stack<int> s;
        int max = 0;
        for (int i = 0; i < n; ++i) {
            if (s.empty() || heights[s.top()] <= heights[i]) s.push(i);
            else {
                while (!s.empty() && heights[s.top()] > heights[i]) {
                    int top = s.top();
                    s.pop();
                    int temp = heights[top] * (s.empty() ? i : i - (s.top() + 1));
                    if (temp > max) max = temp;
                }
                s.push(i);
            }
        }
        return max;
    }
};

// Solution
// 单调栈