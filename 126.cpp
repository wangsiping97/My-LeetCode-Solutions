// Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
// Only one letter can be changed at a time
// Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

// Note:
// Return an empty list if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
// You may assume no duplicates in the word list.
// You may assume beginWord and endWord are non-empty and are not the same.

#include <vector> 
#include <string> 
#include <deque> 
#include <cstdlib> 
#include <unordered_map> 
using namespace std; 

class Solution {
public:
    vector< vector<string> > ans; 
    vector<string> tempans;
    void dfs(unordered_map< int, vector<int> >& map, vector<string>& wordList, int* level, int index) {
        if (index == wordList.size() - 1) {
            ans.push_back(tempans);
            return;
        }
        for (int i = 0; i < map[index].size(); ++i) {
            tempans[level[map[index][i]] - 1] = wordList[map[index][i]];
            dfs(map, wordList, level, map[index][i]);
        }
    }
    vector< vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int n = wordList.size();
        int l = beginWord.length();
        deque<int> q; 
        int* level = (int*)malloc(n * sizeof(int));
        int* pre = (int*)malloc(n * sizeof(int));
        memset(level, 0, n * sizeof(int)); 
        memset(pre, n, n * sizeof(int));
        q.push_back(n - 1);
        level[n - 1] = 1;
        int shortest = n + 1; 
        unordered_map<int, vector<int> > map;
        int index = n - 1;
        while (!q.empty()) {
            int temp = q.front();
            if (level[temp] >= shortest) break;
            q.pop_front();
            for (int i = 0; i < n - 1; ++i) {
                if (level[i] == 0 || level[i] > level[temp]) {
                    int diff = 0;
                    bool flag = true;
                    for (int j = 0; j < l; ++j) {
                        if (wordList[i][j] != wordList[temp][j]) diff++;
                        if (diff == 2) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag == false) continue;
                    map[i].push_back(temp);
                    if (wordList[i] == endWord) {
                        shortest = min(shortest, level[temp] + 1);
                        index = i;
                    };
                    if (level[i] == 0) q.push_back(i);
                    level[i] = level[temp] + 1;
                }
            }
        }
        if (shortest == n + 1) return ans;
        for (int i = 0; i < shortest; ++i) tempans.push_back("");
        tempans[shortest - 1] = endWord;
        dfs(map, wordList, level, index);
        return ans;
    }
};