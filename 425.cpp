// Given a set of words (without duplicates), find all word squares you can build from them.
// A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).
// For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.

// b a l l
// a r e a
// l e a d
// l a d y

#include <vector> 
#include <string> 
#include <unordered_map> 
using namespace std; 

class Node {
public: 
    bool isLeaf;
    string word;
    unordered_map<char, Node*> next;
    Node() {
        isLeaf = false;
    }
};

class Trie {
private: 
    Node* root;
public: 
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node* node = root;
        for (char c : word) {
            if (node->next.count(c) == 0) {
                node->next[c] = new Node();
                node->next[c]->word = node->word + c;
            }
            node = node->next[c];
        }
        node->isLeaf = true;
    }
    // return all words starting with `prefix`
    vector<string> searchPrefix(string prefix) {
        vector<string> res; 
        Node* node = root;
        for (char c : prefix) {
            if (node->next.count(c) == 0) return res;
            node = node->next[c];
        }
        dfs(node, res);
        return res;
    }
    void dfs(Node* node, vector<string> &res) {
        if (node->isLeaf) {
            res.push_back(node->word);
            return;
        }
        unordered_map<char, Node*>::iterator iter;
        for (iter = node->next.begin(); iter != node->next.end(); ++iter) {
            dfs(iter->second, res);
        }
    }
};
class Solution {
public:
    vector< vector<string> > ans;
    vector<string> tmp_ans;
    vector< vector<string> > wordSquares(vector<string>& words) {
        Trie trie = Trie();
        if (words.size() == 0) return ans;
        for (string word : words) {
            trie.insert(word);
        }
        dfs_helper(trie, "", words[0].length());
        return ans;
    }
    void dfs_helper(Trie &trie, string prefix, int length) {
        int l = prefix.length();
        if (l == length) {
            ans.push_back(tmp_ans);
            return;
        }
        vector<string> matched_words = trie.searchPrefix(prefix);
        if (matched_words.empty()) return;
        for (string word : matched_words) {
            tmp_ans.push_back(word);
            string new_prefix;
            for (string tmp_word : tmp_ans) {
                new_prefix.push_back(tmp_word[l + 1]);
            }
            dfs_helper(trie, new_prefix, length);
            tmp_ans.pop_back();
        }
    }
};

// Solution: 
// key information need to make sure: 
// 1. which words 
// 2. the sequence of the words

// prefix tree (example)
//         root
//  a   b     l      w     -> ball, wall
//  r   a    a  e    a     -> area (search for prefix)
//  e   l    d  a    l     -> lead
//  a   l    y  d    l     -> lady
