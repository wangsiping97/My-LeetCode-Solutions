// Given an undirected graph, return true if and only if it is bipartite.
// Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B.
// The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.

#include <vector> 
#include <deque> 
#include <cstdlib> 
using namespace std; 

class Solution {
public:
    bool isBipartite(vector< vector<int> >& graph) {
        deque<int> level;
        int n = graph.size();
        if (n == 0) return false;
        int* color = (int*) malloc(n * sizeof(int));
        memset(color, false, n * sizeof(int));
        for (int i = 0; i < n; ++i) {
            if (color[i] == 0) {
                color[i] = 1;
                level.push_back(i);
            }
            while (!level.empty()) {
                int index = level.front();
                level.pop_front();
                int sz = graph[index].size();
                int c = color[index];
                for (int j = 0; j < sz; ++j) {
                    if (color[graph[index][j]] == c) return false;
                    if (color[graph[index][j]] == 0) {
                        color[graph[index][j]] = -c;
                        level.push_back(graph[index][j]);
                    }
                }
            }
        }
        return true;
    }
};