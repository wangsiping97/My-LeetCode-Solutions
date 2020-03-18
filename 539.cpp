// Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.
// Example 1:
// Input: ["23:59","00:00"]
// Output: 1
// Note:
// The number of time points in the given list is at least 2 and won't exceed 20000.
// The input time is legal and ranges from 00:00 to 23:59.

#include <vector> 
#include <string> 
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        int l = timePoints.size();
        for (int i = 0; i < l; ++i) {
            minutes.push_back(((timePoints[i][0]) * 10 + timePoints[i][1]) * 60 + (timePoints[i][3]) * 10 + timePoints[i][4]);
        }
        sort(minutes.begin(), minutes.end());
        int ans = 24 * 60 + minutes[0] - minutes[l - 1];
        for (int i = 0; i < l - 1; ++i) {
            ans = min(ans, minutes[i + 1] - minutes[i]);
        }
        return ans;
    }
};