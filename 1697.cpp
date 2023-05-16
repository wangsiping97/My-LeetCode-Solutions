// An undirected graph of n nodes is defined by edgeList, where edgeList[i] =
// [ui, vi, disi] denotes an edge between nodes ui and vi with distance disi.
// Note that there may be multiple edges between two nodes. Given an array
// queries, where queries[j] = [pj, qj, limitj], your task is to determine for
// each queries[j] whether there is a path between pj and qj such that each edge
// on the path has a distance strictly less than limitj . Return a boolean array
// answer, where answer.length == queries.length and the jth value of answer is
// true if there is a path for queries[j] is true, and false otherwise.

#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> father;  // father[i] := i's father
  int get_father(int x) {
    if (father[x] == x) return x;
    father[x] = get_father(father[x]);
    return father[x];
  }
  vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList,
                                         vector<vector<int>>& queries) {
    auto comp = [](vector<int>& vec1, vector<int>& vec2) {
      return vec1[2] < vec2[2];
    };
    std::sort(edgeList.begin(), edgeList.end(), comp);
    for (int i = 0; i < queries.size(); ++i) {
      queries[i].push_back(i);
    }
    std::sort(queries.begin(), queries.end(), comp);
    for (int i = 0; i < n; ++i) {
      father.push_back(i);
    }
    int e_idx = 0, q_idx = 0;
    int num_edges = edgeList.size();
    int num_queries = queries.size();
    vector<bool> ans(num_queries);
    while (q_idx < num_queries) {
      int max_len = queries[q_idx][2];
      int u = queries[q_idx][0];
      int v = queries[q_idx][1];
      int idx = queries[q_idx][3];
      // push new edges if possible
      while (e_idx < num_edges && edgeList[e_idx][2] < max_len) {
        int v1 = edgeList[e_idx][0];
        int v2 = edgeList[e_idx][1];
        father[get_father(v2)] = get_father(v1);
        e_idx++;
      }
      // check
      if (get_father(u) == get_father(v)) {
        ans[idx] = true;
      } else {
        ans[idx] = false;
      }
      q_idx++;
    }
    return ans;
  }
};

// Solution
// union-find