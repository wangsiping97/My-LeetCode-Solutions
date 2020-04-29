// Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
// Only one letter can be changed at a time.
// Each transformed word must exist in the word list.

// Note:
// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
// You may assume no duplicates in the word list.
// You may assume beginWord and endWord are non-empty and are not the same.

#include <vector> 
#include <string> 
#include <deque> 
#include <cstdlib> 
using namespace std; 

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int n = wordList.size();
        int l = beginWord.length();
        deque<int> q; 
        int* level = (int*)malloc(n * sizeof(int));
        memset(level, 0, n * sizeof(int)); 
        q.push_back(n - 1);
        level[n - 1] = 1;
        while (!q.empty()) {
            int temp = q.front();
            q.pop_front();
            for (int i = 0; i < n - 1; ++i) {
                if (level[i] == 0) {
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
                    if (wordList[i] == endWord) return level[temp] + 1;
                    q.push_back(i);
                    level[i] = level[temp] + 1;
                }
            }
        }
        return 0;
    }
};

// Solution
// Model generalization: We are given a beginWord and an endWord. Let these two represent start node and end node of a graph. 
// The shortest path problem. 