// Given the following details of a matrix with n columns and 2 rows :
// The matrix is a binary matrix, which means each element in the matrix can be 0 or 1.
// The sum of elements of the 0-th(upper) row is given as upper.
// The sum of elements of the 1-st(lower) row is given as lower.
// The sum of elements in the i-th column(0-indexed) is colsum[i], where colsum is given as an integer array with length n.
// Your task is to reconstruct the matrix with upper, lower and colsum.
// Return it as a 2-D integer array.
// If there are more than one valid solution, any of them will be accepted.
// If no valid solution exists, return an empty 2-D array.

#include <vector> 
using namespace std; 

class Solution {
public:
    vector< vector<int> > reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector< vector<int> > ans;
        vector<int> up;
        vector<int> down;
        ans.push_back(up);
        ans.push_back(down);
        int n = colsum.size();
        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 2) {
                ans[0].push_back(1);
                ans[1].push_back(1);
                upper--;
                lower--;
            }
            else {
                ans[0].push_back(0);
                ans[1].push_back(0);
            }
            if (upper < 0 || lower < 0) {
                ans.clear();
                return ans;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 1 && upper > 0) {
                ans[0][i] = 1;
                ans[1][i] = 0;
                upper--;
            }
            else if (colsum[i] == 1) {
                ans[0][i] = 0;
                ans[1][i] = 1;
                lower--;
            }
            if (upper < 0 || lower < 0) {
                ans.clear();
                return ans;
            }
        }
        if (upper > 0 || lower > 0) ans.clear();
        return ans;
    }
};
