// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

// Note: You may not slant the container and n is at least 2.

// Example:
// Input: [1,8,6,2,5,4,8,3,7]
// Output: 49

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int size(vector<int>& height, int i, int j) {
        return abs((i - j) * min(height[i], height[j]));
    }
    int maxArea(vector<int>& height) {
        int sz = height.size();
        int max = size(height, 0, sz - 1);
        int i = 0, j = sz - 1;
        while (i < j) {
            if (height[i] <= height[j]) {
                int k = i;
                while (i < j && height[i] <= height[k]) {
                    i++;
                }
                if (size(height, i, j) > max) max = size(height, i, j);
            }
            else {
                int k = j;
                while (j > i && height[j] <= height[k]) {
                    j--;
                }
                if (size(height, i, j) > max) max = size(height, i, j);
            }
        }
        return max;
    }
};

int main() {
    Solution s;
}