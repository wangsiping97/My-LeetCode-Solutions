// There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

#include <vector> 
#include <queue> 
using namespace std; 

class Solution {
public:
    bool canFinish(int numCourses, vector< vector<int> >& prerequisites) {
        int degree[numCourses];
        memset(degree, 0, numCourses * sizeof(int)); 
        vector< vector<int> > adj(numCourses, vector<int>(0)); // adjacent matrix
        for (vector<int> v: prerequisites) {
            degree[v[0]]++;
            adj[v[1]].push_back(v[0]);
        }
        queue<int> q; 
        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0) 
            q.push(i);
        }
        int count = 0;
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            count++;
            for (int i: adj[temp]) {
                degree[i]--;
                if (degree[i] == 0) q.push(i);
            }
        }
        return count == numCourses;
    }
};