// Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

// Note:
// If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
// All airports are represented by three capital letters (IATA code).
// You may assume all tickets form at least one valid itinerary.
// One must use all the tickets once and only once.

#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

class Solution
{
public:
    map< string, multiset<string> > adj;
    vector<string> tempans;
    vector<string> ans;
    vector<string> findItinerary(vector<vector<string> > &tickets)
    {
        for (vector<string> v : tickets) {
            adj[v[0]].insert(v[1]);
        }
        tempans.push_back("JFK");
        dfs("JFK");
        return ans;
    }
    void dfs(string from) {
        if (adj[from].empty()) {
            map< string, multiset<string> >::iterator iter;
            for (iter = adj.begin(); iter != adj.end(); iter++) {
                if (!iter->second.empty()) return;
            }
            ans = tempans;
            return;
        }
        if (!ans.empty()) return;
        multiset<string> target = adj[from];
        for (string dest : target) {
            multiset<string>::iterator iter = adj[from].find(dest);
            adj[from].erase(iter);
            tempans.push_back(dest);
            dfs(dest);
            adj[from].insert(dest);
            tempans.pop_back();
        }
    }
};