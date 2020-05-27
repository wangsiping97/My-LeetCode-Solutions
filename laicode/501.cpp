// There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

#include <string> 
#include <vector> 
#include <unordered_map>
#include <deque> 
using namespace std; 

class Solution {
 public:
  string alienOrder(vector<string> words) {
    // write your solution here
    int n = words.size();
    int degree[26];
    string ans = "";
    memset(degree, -1, 26 * sizeof(int));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < words[i].length(); ++j)
            degree[words[i][j] - 'a'] = 0;
    }
    // construct graph
    int map[26][26];
    for (int i = 0; i < 26; ++i) memset(map[i], 0, 26 * sizeof(int));
    for (int i = 0; i < n - 1; ++i) {
        int n1 = words[i].length(), n2 = words[i + 1].length();
        for (int j = 0; j < min(n1, n2); ++j) 
            if (words[i][j] != words[i + 1][j]) {
                if (map[words[i][j] - 'a'][words[i + 1][j] - 'a'] == 0) degree[words[i + 1][j] - 'a']++;
                map[words[i][j] - 'a'][words[i + 1][j] - 'a'] = 1;
                break;
            }
    }
    // topological sort
    deque<int> q;
    int count = 0;
    for(int i = 0; i < 26; ++i) {
        if (degree[i] != -1) count++;
        if (degree[i] == 0) q.push_back(i);
    }
    
    while (!q.empty()) {
        int top = q.front();
        ans += top + 'a';
        q.pop_front();
        for (int i = 0; i < 26; ++i) {
            if (map[top][i] == 1) {
                degree[i]--;
                if (degree[i] == 0) q.push_back(i);
            }
        }
    }

    if (ans.length() != count) ans.clear();
    return ans;
  }
};

// Solution
// Directed graph
