// Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
// Examples:
// [2,3,4] , the median is 3
// [2,3], the median is (2 + 3) / 2 = 2.5
// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Your job is to output the median array for each window in the original array.
// For example,
// Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

#include <vector> 
#include <queue> 
#include <unordered_map> 
using namespace std; 

class Solution {
public:
    priority_queue<int> qlow;
    priority_queue<int, vector<int>, greater<int> > qhigh;
    unordered_map<int, int> map;
    int balance;
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        int size1 = k / 2, size2;
        if (k % 2 == 1) size2 = k / 2 + 1;
        else size2 = size1;
        // begin for the first k elements: 
        int i = 0;
        for (; i < k; ++i) {
            qlow.push(nums[i]);
            qhigh.push(nums[i]);
            if (i >= size1) {
                qlow.pop();
            }
            if (i >= size2) {
                qhigh.pop();
            }
        }
        if (size1 == size2) {
            ans.push_back(((double)qlow.top() + (double)qhigh.top())/ 2);
        } else ans.push_back(qhigh.top());
        // sliding window
        balance = size1 - size2; // size(qlow) - size(qhigh) when balanced
        for(; i < nums.size(); ++i) {
            // update balance
            int del = i - k;
            map[nums[del]]++;
            if (!qlow.empty()) balance += nums[del] > qlow.top() ? -1 : 1;
            else balance += nums[del] < qhigh.top() ? 1 : -1;
            // add nums[i]
            if (!qhigh.empty() && nums[i] >= qhigh.top()) {
                qhigh.push(nums[i]);
            } else if (qhigh.empty() && nums[i] > qlow.top()) {
                qhigh.push(nums[i]);
            } else (qlow.push(nums[i]));
            // balancing
            remove();
            while ((int)qlow.size() - (int)qhigh.size() != balance) {
                if ((int)qlow.size() - (int)qhigh.size() < balance) {
                    qlow.push(qhigh.top());
                    qhigh.pop();
                } else {
                    qhigh.push(qlow.top());
                    qlow.pop();
                }
                remove();
            }
            if (size1 == size2) {
                ans.push_back(((double)qlow.top() + (double)qhigh.top())/ 2);
            } else ans.push_back(qhigh.top());
        }
        return ans;
    }
    void remove() {
        while (!qlow.empty() && map[qlow.top()] >= 1) {
            balance --;
            map[qlow.top()]--;
            qlow.pop();
        }
        while (!qhigh.empty() && map[qhigh.top()] >= 1) {
            balance ++;
            map[qhigh.top()]--;
            qhigh.pop();
        }
    }
};