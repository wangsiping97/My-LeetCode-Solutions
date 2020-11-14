// (This problem is the same as Minimize Malware Spread, with the differences bolded.)
// In a network of nodes, each node i is directly connected to another node j if and only if graph[i][j] = 1.
// Some nodes initial are initially infected by malware.  Whenever two nodes are directly connected and at least one of those two nodes is infected by malware, both nodes will be infected by malware.  This spread of malware will continue until no more nodes can be infected in this manner.
// Suppose M(initial) is the final number of nodes infected with malware in the entire network, after the spread of malware stops.
// We will remove one node from the initial list, completely removing it and any connections from this node to any other node.  Return the node that if removed, would minimize M(initial).  If multiple nodes could be removed to minimize M(initial), return such a node with the smallest index.

#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int minMalwareSpread(vector< vector<int> > &graph, vector<int> &initial)
    {
        sort(initial.begin(), initial.end());
        int n = graph.size();
        queue<int> q;
        int parent[n], isSingleParent[n];
        for (int i = 0; i < n; ++i)
        {
            parent[i] = -1;
            isSingleParent[i] = 0;
        }
        for (int p : initial)
        {
            parent[p] = p;
            isSingleParent[p] = 1;
        }
        // bfs
        for (int i = 0; i < initial.size(); i++)
        {
            q.push(initial[i]);
            while (!q.empty())
            {
                int now = q.front();
                q.pop();
                for (int j = 0; j < n; j++)
                {
                    if (graph[now][j])
                    {
                        if (parent[j] == j || parent[j] == initial[i])
                            continue;
                        parent[j] = initial[i];
                        isSingleParent[j]++;
                        q.push(j);
                    }
                }
            }
        }
        // i its childreon with isSingleParent[child] == 1, maximum
        int max = -1, ans = -1;
        for (int idx : initial)
        {
            int count = 0;
            for (int i = 0; i < n; ++i)
            {
                if (parent[i] == idx && isSingleParent[i] == 1)
                    count++;
            }
            if (count > max)
            {
                max = count;
                ans = idx;
            }
        }
        return ans;
    }
};