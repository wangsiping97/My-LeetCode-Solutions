// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
// Return intervals after the insertion.

#include <vector> 
using namespace std; 

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        if (n == 0) {
            ans.emplace_back(newInterval);
            return ans;
        }
        int new_start = newInterval[0];
        int new_end = newInterval[1];
        // binary search find lower bound of new_start
        auto comp_start = [&](vector<int>& a, int value) {
            return a[0] < value;
        };
        int left = std::lower_bound(intervals.begin(), intervals.end(), new_start, comp_start) - intervals.begin();
        // binary search find upper bound of new_end
        auto comp_end = [&](int value, vector<int>& a) {
            return value < a[1];
        };
        int right = std::upper_bound(intervals.begin(), intervals.end(), new_end, comp_end) - intervals.begin();
        
        for (int i = 0; i < left; ++i) {
            ans.emplace_back(intervals[i]);
        }
        
        // overlapping
        int pos = 0;
        if (left == 0) {
            ans.emplace_back(newInterval);
            pos = 0;
        } else if (ans[left-1][1] < new_start){
            ans.emplace_back(newInterval);
            pos = left;
        } else {
            ans[left-1][1] = new_end;
            pos = left-1;
        }
        if (right == n) {
            ans[pos][1] = new_end;
            return ans;
        }
        if (ans[pos][1] < intervals[right][0]) {
            pos = right;
        } else {
            ans[pos][1] = intervals[right][1];
            pos = right+1;
        }
        for (pos; pos < n; ++pos) {
            ans.emplace_back(intervals[pos]);
        }
        return ans;
    }
};