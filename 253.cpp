// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

#include <vector> 

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> starts;
        vector<int> ends;
        int n = intervals.size();
        if (n == 0) return 0;
        if (n == 1) return 1;
        for (int i = 0; i < n; ++i) {
            starts.push_back(intervals[i][0]);
            ends.push_back(intervals[i][1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int ans = 0;
        int free = 0;
        int i = 0, j = 0;
        while (i < n && j < n) {
            if (starts[i] < ends[j]) {
                if (free > 0) free--;
                else ans++;
                i++;
            } else {
                free++;
                j++;
            }
        }
        return ans;
    }
};