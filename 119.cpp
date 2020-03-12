// Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

// Note that the row index starts from 0.

#include <vector> 
using namespace std;

class Solution {
public:
    vector< vector<int> > ans;
    inline void generate_new() {
        int l = ans.size();
        vector<int> last = ans[l - 1];
        vector<int> newline;
        newline.push_back(1);
        for (int i = 0; i < l - 1; ++i) {
            newline.push_back(last[i] + last[i + 1]);
        }
        newline.push_back(1);
        ans.push_back(newline);
    }
    vector<int> getRow(int rowIndex) {
        vector<int> first(1,1);
        if (rowIndex == 0) return first;
        ans.push_back(first);
        for (int i = 1; i <= rowIndex; ++i)
            generate_new();
        return ans[rowIndex];
    }
};