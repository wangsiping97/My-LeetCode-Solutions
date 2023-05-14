// There is a country of n cities numbered from 0 to n - 1 where all the cities
// are connected by bi-directional roads. The roads are represented as a 2D
// integer array edges where edges[i] = [xi, yi, timei] denotes a road between
// cities xi and yi that takes timei minutes to travel. There may be multiple
// roads of differing travel times connecting the same two cities, but no road
// connects a city to itself. Each time you pass through a city, you must pay a
// passing fee. This is represented as a 0-indexed integer array passingFees of
// length n where passingFees[j] is the amount of dollars you must pay when you
// pass through city j. In the beginning, you are at city 0 and want to reach
// city n - 1 in maxTime minutes or less. The cost of your journey is the
// summation of passing fees for each city that you passed through at some
// moment of your journey (including the source and destination cities). Given
// maxTime, edges, and passingFees, return the minimum cost to complete your
// journey, or -1 if you cannot complete it within maxTime minutes.

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxTime_;
  unordered_map<int, vector<int>> graph;
  int time[1010][1010];
  int memo[1010][1010];  // memo[i][j] := minimum cost from city i to city n-1
                         // when curTime = j
  int helper(int dest, int curTime, vector<int>& passingFees) {
    if (memo[dest][curTime] != -1) {
      return memo[dest][curTime];
    }
    if (dest == passingFees.size() - 1) {
      memo[dest][curTime] = passingFees[dest];
      return passingFees[dest];
    }
    int min = INT_MAX;
    for (int city : graph[dest]) {
      int newTime = curTime + time[dest][city];
      if (newTime > maxTime_) continue;
      int res = helper(city, newTime, passingFees);
      if (res < min) {
        min = res;
      }
    }
    if (min != INT_MAX) {
      memo[dest][curTime] = min + passingFees[dest];
    } else {
      memo[dest][curTime] = min;
    }
    return memo[dest][curTime];
  }
  int minCost(int maxTime, vector<vector<int>>& edges,
              vector<int>& passingFees) {
    maxTime_ = maxTime;
    memset(time, -1, sizeof(time));
    memset(memo, -1, sizeof(memo));
    int n = passingFees.size();
    // build graph
    for (auto edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
      if (time[edge[0]][edge[1]] == -1 || edge[2] < time[edge[0]][edge[1]]) {
        time[edge[0]][edge[1]] = edge[2];
        time[edge[1]][edge[0]] = edge[2];
      }
    }
    int res = helper(0, 0, passingFees);
    return (res == INT_MAX) ? -1 : res;
  }
};