// Given an m x n matrix, return a new matrix answer where answer[row][col] is the rank of matrix[row][col].

// The rank is an integer that represents how large an element is compared to other elements. It is calculated using the following rules:

// The rank is an integer starting from 1.
// If two elements p and q are in the same row or column, then:
// If p < q then rank(p) < rank(q)
// If p == q then rank(p) == rank(q)
// If p > q then rank(p) > rank(q)
// The rank should be as small as possible.

#include <iostream> 
#include <unordered_map>
#include <vector> 
#include <cmath>


using namespace std;


class Solution {
public:
    vector<int> father;
    int get_father(int x) {
        return father[x] == x ? x : father[x] = get_father(father[x]);
    }
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        int m = matrix.size();
        if (m == 0) {
            return ans;
        }
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            vector<int> tmp;
            for (int j = 0; j < n; ++j) {
                tmp.push_back(0);
            }
            ans.push_back(tmp);
        }

        for (int i = 0; i < n * m; ++i) {
            father.emplace_back(i);
        }

        auto comp_v_x = [&](tuple<int, int, int>& a, tuple<int, int, int>& b) {
            if (get<0>(a) != get<0>(b)) {
                return get<0>(a) < get<0>(b);
            } 
            return get<1>(a) < get<1>(b);
        };

        auto comp_v_y = [&](tuple<int, int, int>& a, tuple<int, int, int>& b) {
            if (get<0>(a) != get<0>(b)) {
                return get<0>(a) < get<0>(b);
            } 
            return get<2>(a) < get<2>(b);
        };

        vector<tuple<int, int, int>> data;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                data.emplace_back(make_tuple(matrix[i][j], i, j));
            }
        }
        
        sort(data.begin(), data.end(), comp_v_x);

        for (int i = 1; i < n * m; ++i) {
            auto [v1, x1, y1] = data[i - 1];
            auto [v2, x2, y2] = data[i];
            if (v1 == v2 && x1 == x2) {
                int key1 = x1 * n + y1;
                int key2 = x2 * n + y2;
                father[get_father(key2)] = get_father(key1);
            }
        }

        sort(data.begin(), data.end(), comp_v_y);
        
        for (int i = 1; i < n * m; ++i) {
            auto [v1, x1, y1] = data[i - 1];
            auto [v2, x2, y2] = data[i];
            if (v1 == v2 && y1 == y2) {
                int key1 = x1 * n + y1;
                int key2 = x2 * n + y2;
                father[get_father(key2)] = get_father(key1);
            }
        }

        vector<int> row_maxes(m);
        vector<int> col_maxes(n);
        unordered_map<int, int> rank_map;
        int rank = 0;
        

        for (int r = 0, l = 0; r < n * m; l = r) {
            while (r < n * m && get<0>(data[r]) == get<0>(data[l])) {
                r++;
            }
           
            for (int i = l; i < r; ++i) {
                auto [v, x, y] = data[i];
                int key = x * n + y;
                int father = get_father(key);
                rank_map[father] = max(rank_map[father], max(row_maxes[x] + 1, col_maxes[y] + 1));
            }

            for (int i = l; i < r; ++i) {
                auto [v, x, y] = data[i];
                int key = x * n + y;
                int father = get_father(key);
                int res = rank_map[father];
                ans[x][y] = res;
                row_maxes[x] = res;
                col_maxes[y] = res;
            }
        }

        return ans;

    }
};