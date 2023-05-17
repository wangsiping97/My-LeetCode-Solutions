// You are given a directed graph of n nodes numbered from 0 to n - 1, where
// each node has at most one outgoing edge. The graph is represented with a
// given 0-indexed array edges of size n, indicating that there is a directed
// edge from node i to node edges[i]. If there is no outgoing edge from node i,
// then edges[i] == -1. Return the length of the longest cycle in the graph. If
// no cycle exists, return -1. A cycle is a path that starts and ends at the
// same node.

#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> layers;
  int calculateCircle(int node, vector<int>& edges) {
    unordered_set<int> visited;
    visited.insert(node);
    layers[node] = 0;
    int cur = edges[node];
    int c = 1;
    while (cur >= 0) {
      if (layers[cur] >= 0) {
        if (visited.find(cur) == visited.end()) return -1;
        // found circle
        return c - layers[cur];
      } else {
        visited.insert(cur);
        layers[cur] = c;
        cur = edges[cur];
        c++;
      }
    }
    // no circle found
    return -1;
  }
  int longestCycle(vector<int>& edges) {
    int n = edges.size();
    int in_degrees[n];
    memset(in_degrees, 0, sizeof(in_degrees));
    for (int i = 0; i < n; ++i) {
      layers.push_back(-1);
    }
    // build graph
    for (int i = 0; i < n; ++i) {
      if (edges[i] >= 0) {
        in_degrees[edges[i]]++;
      }
    }
    // find longest circle
    int res = -1;
    for (int i = 0; i < n; ++i) {
      if (in_degrees[i] == 0) continue;
      if (layers[i] >= 0) continue;
      int c = calculateCircle(i, edges);
      if (c > res) {
        res = c;
      }
    }
    return res;
  }
};