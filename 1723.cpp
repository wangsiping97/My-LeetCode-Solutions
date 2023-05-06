// You are given an integer array jobs, where jobs[i] is the amount of time it
// takes to complete the ith job. There are k workers that you can assign jobs
// to. Each job should be assigned to exactly one worker. The working time of a
// worker is the sum of the time it takes to complete all jobs assigned to them.
// Your goal is to devise an optimal assignment such that the maximum working
// time of any worker is minimized. Return the minimum possible maximum working
// time of any assignment.

#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int min_max = 1000000000;
  vector<int> workloads;
  void dfs(vector<int>& jobs, int job_id) {
    if (job_id == jobs.size()) {
      int tmp_max = 0;
      for (int workload : workloads) {
        if (workload > tmp_max) tmp_max = workload;
      }
      if (tmp_max < min_max) {
        min_max = tmp_max;
      }
      return;
    }
    int work = jobs[job_id];
    unordered_set<int> work_set;
    for (int i = 0; i < workloads.size(); ++i) {
      if (workloads[i] + work >= min_max) continue;
      if (work_set.find(workloads[i]) == work_set.end()) {
        work_set.insert(workloads[i]);
        workloads[i] += work;
        dfs(jobs, job_id + 1);
        workloads[i] -= work;
      }
    }
  }
  int minimumTimeRequired(vector<int>& jobs, int k) {
    for (int i = 0; i < k; ++i) {
      workloads.push_back(0);
    }
    dfs(jobs, 0);
    return min_max;
  }
};