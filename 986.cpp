// Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.
// Return the intersection of these two interval lists.
// (Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        int m = firstList.size();
        int n = secondList.size();
        int i = 0, j = 0;
        vector<vector<int>> result;
        while (i < m && j < n)
        {
            vector<int> interval1 = firstList[i];
            vector<int> interval2 = secondList[j];
            int start = max(interval1[0], interval2[0]);
            int end = min(interval1[1], interval2[1]);
            if (start <= end)
            {
                result.push_back({start, end});
            }
            if (interval1[1] < interval2[1])
            {
                i++;
            }
            else if (interval1[1] > interval2[1])
            {
                j++;
            }
            else
            {
                i++;
                j++;
            }
        }
        return result;
    }
};