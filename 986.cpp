// Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.
// Return the intersection of these two interval lists.
// (Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

#include <vector> 
using namespace std; 

class Solution {
public:
    vector< vector<int> > intervalIntersection(vector< vector<int> >& A, vector< vector<int> >& B) {
        vector< vector<int> > ans;
        vector<int> tempans;
        int m = A.size();
        int n = B.size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (A[i][0] < B[j][0]) {
                if (A[i][1] >= B[j][0]) {
                    tempans.clear();
                    tempans.push_back(B[j][0]);
                    tempans.push_back(min(A[i][1], B[j][1]));
                    ans.push_back(tempans);
                    if (A[i][1] < B[j][1]) 
                        i++;
                    else if (A[i][1] > B[j][1]) 
                        j++;
                    else {
                        i++;
                        j++;
                    }
                } else {
                    i++;
                }
            } else if (A[i][0] > B[j][0]) {
                if (B[j][1] >= A[i][0]) {
                    tempans.clear();
                    tempans.push_back(A[i][0]);
                    tempans.push_back(min(A[i][1], B[j][1]));
                    ans.push_back(tempans);
                    if (A[i][1] <= B[j][1]) 
                        i++;
                    else if (A[i][1] >= B[j][1])
                        j++;
                    else {
                        i++;
                        j++;
                    }
                } else {
                    j++;
                }
            } else {
                tempans.clear();
                tempans.push_back(A[i][0]);
                tempans.push_back(min(A[i][1], B[j][1]));
                ans.push_back(tempans);
                if (A[i][1] < B[j][1]) 
                    i++;
                else if (A[i][1] > B[j][1])
                    j++;
                else {
                    i++;
                    j++;
                }
            }
        }
        return ans;
    }
};