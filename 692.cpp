// Given a non-empty list of words, return the k most frequent elements.
// Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

#include <vector> 
#include <queue> 
#include <unordered_map> 
using namespace std; 

class Compare {
public: 
    bool operator() (pair<string, int> p1, pair<string, int> p2) {
        if (p1.second == p2.second) return p1.first < p2.first;
        return p1.second > p2.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (string str : words) {
            m[str]++;
        }
        priority_queue<pair<string, int>, vector< pair<string, int> >, Compare> q;
        for (unordered_map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
            q.push(pair<string, int>(iter->first, iter->second));
            if (q.size() > k) q.pop();
        }
        vector<string> ans;
        while (!q.empty()) {
            ans.push_back(q.top().first);
            q.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};