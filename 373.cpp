// You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
// Define a pair (u,v) which consists of one element from the first array and one element from the second array.
// Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

#include <vector> 
#include <queue> 
using namespace std; 

class Compare {
public: 
    bool operator()(pair<int, pair<int,int> > p1, pair<int, pair<int,int> > p2) {
        return p1.first + p1.second.first > p2.first + p2.second.first;
    }
};

class Solution {
public:
    vector< vector<int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int,int> > , vector< pair<int, pair<int,int> > >, Compare> q;
        vector< vector<int> > ans; 
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 == 0 || n2 == 0) return ans;
        for (int i = 0; i < n2 && i < k; ++i) {
            pair<int, pair<int, int> > p(nums2[i], pair<int,int>(nums1[0], 0));
            q.push(p);
        }
        for (int i = 0; i < k && !q.empty(); ++i) {
            pair<int, pair<int, int> > p = q.top();
            vector<int> tmp = {p.second.first, p.first};
            ans.push_back(tmp);
            q.pop();
            if (p.second.second + 1 < n1) 
                q.push(pair<int, pair<int, int> >(p.first, pair<int, int>(nums1[p.second.second + 1], p.second.second + 1)));
        }
        return ans;
    }
};