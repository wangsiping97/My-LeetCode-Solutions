// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int v : nums) 
            freqMap[v]++;
        vector<pair<int, int>> pairs;
        for (auto pair : freqMap)
            pairs.emplace_back(pair);
        
        vector<int> ans;
        sort(pairs.begin(), pairs.end(), cmp);
        for (int i = 0; i <k; ++i) {
            ans.emplace_back(pairs[i].first);
        }
        return ans;
    }
};

// Note: 
// When sorting map based on value, 
// you can first put all pairs into a vector,
// then sort the vector based on the cmp function.