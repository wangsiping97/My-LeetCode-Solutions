// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

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
    vector< vector<int> > generate(int numRows) {
        if (numRows == 0) return ans;
        vector<int> first(1, 1);
        ans.push_back(first);
        for (int i = 1; i < numRows; ++i)
            generate_new();
        return ans;
    }
};