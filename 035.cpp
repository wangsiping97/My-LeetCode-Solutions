// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
// You may assume no duplicates in the array.

// Example 1:
// Input: [1,3,5,6], 5
// Output: 2

// Example 2:
// Input: [1,3,5,6], 2
// Output: 1

// Example 3:
// Input: [1,3,5,6], 7
// Output: 4

// Example 4:
// Input: [1,3,5,6], 0
// Output: 0

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i;
        for (i = 0; i < nums.size(); i++) 
            if (nums[i] >= target) return i;
        return nums.size();
    }
};

int main() {
    Solution s;
    int a1[0] = {};
    int a2[4] = {1, 3, 5, 6};
    vector<int> a(a1, a1);
    vector<int> b(a2, a2 + 4);
    cout << s.searchInsert(a, 0) << endl;
    cout << s.searchInsert(b, 5) << endl;
    cout << s.searchInsert(b, 2) << endl;
    cout << s.searchInsert(b, 7) << endl;
    cout << s.searchInsert(b, 0) << endl;
    return 0;
}