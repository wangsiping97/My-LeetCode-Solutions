// There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.
// Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

#include <vector> 
#include <cstdlib> 
using namespace std; 

class Solution {
public:
    int ans; 
    int* searched;
    void dfs(int i, vector< vector<int> >& M, int n) {
        searched[i] = 1;
        bool flag = false;
        for (int j = i + 1; j < n; ++j) {
            if (searched[j] == 0 && M[i][j] == 1) {
                flag = true;
                dfs(j, M, n);
            }
        }
        if (flag == false) ans++;
    }
    int findCircleNum(vector< vector<int> >& M) {
        ans = 0;
        int n = M.size();
        if (n == 0) return 0; 
        searched = (int*)malloc(n * sizeof(int));
        memset(searched, 0, n * 4);
        for (int i = 0; i < n; ++i) {
            if (searched[i] == 0) dfs(i, M, n);
        }
        return ans;
    }
};