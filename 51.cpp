// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

#include <vector> 
#include <string> 
#include <cstdlib> 
#include <iostream> 
using namespace std; 

class Solution {
public:
    vector< vector<string> > ans;
    vector<int> temp;
    int* used;
    void dfs(int n) {
        if (temp.size() == n) {
            vector<string> thisans;
            for (int j = 0; j < n; ++j) {
                string str = "";
                for (int k = 0; k < n; ++k) {
                    if (k == temp[j] - 1) str = str + "Q";
                    else str = str + ".";
                }
                thisans.push_back(str);
            }
            ans.push_back(thisans);
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if (used[i - 1] == 0) {
                bool flag = true;
                int k1 = i - temp.size();
                int k2 = i + temp.size();
                for (int j = 0; j < temp.size(); ++j) {
                    if (temp[j] - j == k1 || temp[j] + j == k2) {
                        flag = false;
                        break;
                    }
                }
                if (flag == false) continue;
                used[i - 1] = 1;
                temp.push_back(i);
                dfs(n);
                used[i - 1] = 0;
                temp.pop_back();
            }
        }
    }
    vector< vector<string> > solveNQueens(int n) {
        used = (int*)malloc(n * sizeof(int));
        memset(used, 0, n * 4);
        dfs(n);
        return ans;
    }
};

int main() {
    Solution s;
    s.solveNQueens(4);
}