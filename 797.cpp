// Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.
// The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

#include <vector> 
#include <cstdlib> 
using namespace std; 

class Solution {
public:
    vector< vector<int> > ans; 
    vector<int> temp; 
    void dfs(int i, vector< vector<int> >& graph, int v) {
        if (i == v - 1) {
            ans.push_back(temp);
            return;
        }
        for (int j = 0; j < graph[i].size(); ++j) {
                temp.push_back(graph[i][j]);
                dfs(graph[i][j], graph, v);
                temp.pop_back();
        }
    }
    vector< vector<int> > allPathsSourceTarget(vector< vector<int> >& graph) {
        int v = graph.size();
        if (v == 0) return ans; 
        temp.push_back(0);
        dfs(0, graph, v);
        return ans;
    }
};