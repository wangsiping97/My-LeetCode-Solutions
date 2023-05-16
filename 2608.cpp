// There is a bi-directional graph with n vertices, where each vertex is labeled
// from 0 to n - 1. The edges in the graph are represented by a given 2D integer
// array edges, where edges[i] = [ui, vi] denotes an edge between vertex ui and
// vertex vi. Every vertex pair is connected by at most one edge, and no vertex
// has an edge to itself. Return the length of the shortest cycle in the graph.
// If no cycle exists, return -1. A cycle is a path that starts and ends at the
// same node, and each edge in the path is used only once.

#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  unordered_map<int, vector<int>> graph;
  int calculateCircle(int n, int node) {
    int res = n + 1;
    int layers[n];
    int fathers[n];
    memset(layers, -1, sizeof(layers));
    memset(fathers, -1, sizeof(fathers));
    queue<int> q;
    q.push(node);
    layers[node] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : graph[u]) {
        if (layers[v] == -1) {
          // add new node to queue
          q.push(v);
          layers[v] = layers[u] + 1;
          fathers[v] = u;
        } else if (layers[v] <= layers[u] + 1 && fathers[u] != v) {
          // found circle
          int c = layers[v] + layers[u] + 1;
          if (c < res) {
            res = c;
          }
        }
      }
    }
    return res;
  }
  int findShortestCycle(int n, vector<vector<int>>& edges) {
    // build graph
    for (auto edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }
    int res = n + 1;
    for (int i = 0; i < n; ++i) {
      int c = calculateCircle(n, i);
      if (c < res) {
        res = c;
      }
    }
    return res == n + 1 ? -1 : res;
  }
};

// Solution
// For each v, calculate the shortest length of circle contains v using bfs