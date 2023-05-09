// You are given an integer n indicating there are n people numbered from 0 to n
// - 1. You are also given a 0-indexed 2D integer array meetings where
// meetings[i] = [xi, yi, timei] indicates that person xi and person yi have a
// meeting at timei. A person may attend multiple meetings at the same time.
// Finally, you are given an integer firstPerson. Person 0 has a secret and
// initially shares the secret with a person firstPerson at time 0. This secret
// is then shared every time a meeting takes place with a person that has the
// secret. More formally, for every meeting, if a person xi has the secret at
// timei, then they will share the secret with person yi, and vice versa. The
// secrets are shared instantaneously. That is, a person may receive the secret
// and share it with people in other meetings within the same time frame. Return
// a list of all the people that have the secret after all the meetings have
// taken place. You may return the answer in any order.

#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<bool> known;
  vector<int> visited;
  void update(unordered_map<int, vector<int>>& graph, int time) {
    queue<int> q;
    for (auto entry : graph) {
      if (known[entry.first]) {
        q.push(entry.first);
      }
    }
    while (!q.empty()) {
      int u = q.front();
      known[u] = true;
      q.pop();
      if (visited[u] == time) continue;
      visited[u] = time;
      for (int v : graph[u]) {
        if (visited[v] < time) {
          q.push(v);
        }
      }
    }
  }
  vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                            int firstPerson) {
    for (int i = 0; i < n; ++i) {
      known.push_back(false);
      visited.push_back(0);
    }
    map<int, unordered_map<int, vector<int>>> graph;
    for (auto meet : meetings) {
      graph[meet[2]][meet[0]].push_back(meet[1]);
      graph[meet[2]][meet[1]].push_back(meet[0]);
    }
    known[0] = true;
    known[firstPerson] = true;
    for (auto entry : graph) {
      update(entry.second, entry.first);
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      if (known[i]) ans.push_back(i);
    }
    return ans;
  }
};
