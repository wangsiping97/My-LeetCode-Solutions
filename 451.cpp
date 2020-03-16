// Given a string, sort it in decreasing order based on the frequency of characters.

// Example 1:
// Input:
// "tree"
// Output:
// "eert"
// Explanation:
// 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

#include <string> 
#include <utility> // pair
#include <vector> 
using namespace std; 

class Solution {
public:
    // Note: must be static function
    static bool comp(pair<char, int> a, pair<char, int> b) {
        return a.second >= b.second;
    }
    string frequencySort(string s) {
        int arr[128];
        memset(arr, 0, 128*4);
        int l = s.length();
        for (int i = 0; i < l; ++i) {
            arr[s[i] - ' ']++;
        }
        vector< pair<char, int> > vp;
        for (int i = 0; i < 128; ++i) {
            if (arr[i] > 0)
                vp.push_back(pair<char, int>(i + ' ', arr[i]));
        }
        sort(vp.begin(), vp.end(), comp);
        int sz = vp.size();
        string ans = "";
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < vp[i].second; ++j)
                ans += vp[i].first;
        }
        return ans;
    }
};