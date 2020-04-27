// Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.
// Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.
// After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

#include <unordered_map> 
#include <vector> 
#include <string> 
#include <cstdlib> 
#include <iostream> 
using namespace std; 

class Solution {
public:
    vector< vector<string> > ans;
    bool* checked;
    uint32_t time33(string str) {
        unsigned long  hash = 0;
        int len = str.length();
        for (int i = 0; i < len; i++) {
            hash = hash *33 + (unsigned long) str[i];
        }
        return hash;
    }
    void dfs(int index, vector< vector<string> >& accounts, unordered_map<uint32_t, vector<int> >& map, vector<string>& temp) {
        checked[index] = true; 
        int m = accounts[index].size();
        for (int i = 1; i < m; ++i) {
            vector<int> v = map[time33(accounts[index][i])];
            int sz = v.size();
            if (sz > 0) {
                temp.push_back(accounts[index][i]);
                map[time33(accounts[index][i])].clear();
                for (int j = 0; j < sz; ++j) {
                    if (checked[v[j]] == false)
                        dfs(v[j], accounts, map, temp);
                }
            }
        }
    }
    vector< vector<string> > accountsMerge(vector< vector<string> >& accounts) {
        int n = accounts.size();
        unordered_map<uint32_t, vector<int> > map;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) 
                map[time33(accounts[i][j])].push_back(i); // name index
        }
        checked = (bool*) malloc(n * sizeof(bool));
        memset(checked, false, n * sizeof(bool));
        for (int i = 0; i < n; ++i) {
            if (checked[i] == false) {
                vector<string> temp;
                temp.push_back(accounts[i][0]); // name
                dfs(i, accounts, map, temp);
                if (temp.size() > 1) {
                    sort(temp.begin()++, temp.end());
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};

// Solution
// Bipartie Graph & dfs
// adjacent list 不能偷懒