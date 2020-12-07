// In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. For example, when the root "an" is followed by the successor word "other", we can form a new word "another".
// Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. If a successor can be replaced by more than one root, replace it with the root that has the shortest length.
// Return the sentence after the replacement.

#include <vector> 
#include <string> 
#include <unordered_map> 
using namespace std; 

class TrieNode {
public: 
    bool isLeaf;
    unordered_map<char, TrieNode*> next;
    TrieNode() {
        isLeaf = false;
    }
};

class Trie {
private: 
    TrieNode* root;
public: 
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (cur->next.count(c) == 0) cur->next[c] = new TrieNode();
            cur = cur->next[c];
        }
        cur->isLeaf = true;
    }
    string findShortestPrefix(string word) {
        TrieNode* cur = root;
        string ans; 
        for (char c : word) {
            if (cur->isLeaf == true) return ans;
            if (cur->next.count(c) == 0) return "";
            cur = cur->next[c];
            ans.push_back(c);
        }
        return "";
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie = Trie();
        for (string prefix : dictionary) trie.insert(prefix);
        string ans;
        int l = sentence.length();
        if (l == 0) return ans;
        int pre = 0;
        for (int i = 0; i < l; ++i) {
            if (sentence[i] == ' ' || i == l - 1) {
                string word;
                if (sentence[i] == ' ') word = sentence.substr(pre, i - pre);
                else word = sentence.substr(pre, l - pre);
                pre = i + 1;
                string prefix = trie.findShortestPrefix(word);
                ans += prefix == "" ? word : prefix;
                ans.push_back(' ');
            }
        }
        ans.pop_back();
        return ans;
    }
};