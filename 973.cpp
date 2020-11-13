// We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
// (Here, the distance between two points on a plane is the Euclidean distance.)
// You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

#include <vector> 
#include <unordered_map> 
#include <queue> 
using namespace std; 

class Compare {
public: 
    bool operator() (pair<int, long long> p1, pair<int, long long> p2) {
        return p1.second < p2.second;
    }
};

class Solution {
public:
    vector< vector<int> > kClosest(vector< vector<int> >& points, int K) {
        unordered_map<int, long long> m;
        for (int i = 0; i < points.size(); ++i) 
            m[i] = points[i][0] * points[i][0] + points[i][1] * points[i][1];
        priority_queue<pair<int, long long>, vector< pair<int, long long> >, Compare> q;
        for (unordered_map<int, long long>::iterator iter = m.begin(); iter != m.end(); iter++) {
            q.push(pair<int, long long>(iter->first, iter->second));
            if (q.size() > K) q.pop(); 
        }
        vector< vector<int> > ans;
        while (!q.empty()) {
            ans.push_back(points[q.top().first]);
            q.pop();
        }
        return ans;
    }
};