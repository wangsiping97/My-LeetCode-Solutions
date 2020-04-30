// There are a total of n courses you have to take, labeled from 0 to n-1.
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
// Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
// There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

#include <vector> 
#include <deque> 
#include <cstdlib> 
using namespace std; 

class Solution {
public:
    vector<int> findOrder(int numCourses, vector< vector<int> >& prerequisites) {
        int* degree = (int*)malloc(numCourses * sizeof(int));
        memset(degree, 0, numCourses * sizeof(int));
        int sz = prerequisites.size();
        deque<int> q;
        vector<int> ans;
        vector< vector<int> > adj(numCourses, vector<int>(0)); // 邻接表数组
        for (int i = 0; i < sz; ++i) {
            degree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (degree[i] == 0) q.push_back(i);
        }
        while (!q.empty()) {
            int temp = q.front();
            ans.push_back(temp);
            q.pop_front();
            for (int i = 0; i < adj[temp].size(); ++i) {
                degree[prerequisites[i][0]]--;
                if (degree[prerequisites[i][0]] == 0) q.push_back(prerequisites[i][0]);
            }
        }
        if (ans.size() != numCourses) ans.clear();
        return ans;
    }
};

// Solution
// (1) model generalization: use an array to maintain the in-degree of each course.
// (2) topological sort (push nodes with 0 in-degree and delete their edges.)