// There exists an undirected and unrooted tree with n nodes indexed from 0 to n
// - 1. You are given an integer n and a 2D integer array edges of length n - 1,
// where edges[i] = [ai, bi] indicates that there is an edge between nodes ai
// and bi in the tree. You are also given an array coins of size n where
// coins[i] can be either 0 or 1, where 1 indicates the presence of a coin in
// the vertex i.

// Initially, you choose to start at any vertex in the tree. Then, you can
// perform the following operations any number of times:

// Collect all the coins that are at a distance of at most 2 from the current
// vertex, or Move to any adjacent vertex in the tree. Find the minimum number
// of edges you need to go through to collect all the coins and go back to the
// initial vertex.

// Note that if you pass an edge several times, you need to count it into the
// answer several times.

#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
    // build the graph
    int n = coins.size();
    vector<unordered_set<int>> graph(n);
    for (auto edge : edges) {
      graph[edge[0]].insert(edge[1]);
      graph[edge[1]].insert(edge[0]);
    }
    // cut edges
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (graph[i].size() == 1 && coins[i] == 0) {
        q.push(i);
      }
    }
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      // u must not be coin
      if (graph[u].empty()) continue;
      int v = *(graph[u].begin());
      graph[u].erase(v);
      graph[v].erase(u);
      if (graph[v].size() == 1 && coins[v] == 0) {
        q.push(v);
      }
    }
    // topological sort
    int depth[n];
    for (int i = 0; i < n; ++i) {
      depth[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
      if (graph[i].size() == 1) {
        depth[i] = 0;
        q.push(i);
      }
    }
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (graph[u].empty()) continue;
      int v = *(graph[u].begin());
      graph[u].erase(v);
      graph[v].erase(u);
      if (graph[v].size() == 1) {
        depth[v] = depth[u] + 1;
        q.push(v);
      }
    }
    int count = 0;
    for (int d : depth) {
      if (d >= 2) count++;
    }
    if (count > 0)
      return 2 * (count - 1);
    else
      return 0;
  }
};

// Solution
// step 1: cut edges (remove leafs with no coin)
// step 2: topological sort