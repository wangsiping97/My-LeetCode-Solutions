// Given a pattern and a string str, find if str follows the same pattern.
// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

#include <string> 
#include <sstream>
#include <vector> 
#include <map> 
#include <cstdlib>
using namespace std; 

class Solution {
public:
    vector<string> split(string str) {
        vector<string> vstr;
        vstr.clear(); 
        istringstream iss(str);
        string temp;
        while (getline(iss, temp, ' ')) {
            vstr.push_back(temp);
        }
        return vstr;
    }
    bool wordPattern(string pattern, string str) {
        vector<string> vstr = split(str);
        int l = vstr.size();
        int ll = pattern.length();
        if (ll != l) return false;
        map<string, int> m1;
        map<char, int> m2;
        int p1 = 1, p2 = 1;
        for (int i = 0; i < l; ++i) {
            if (!m1[vstr[i]]) {
                m1[vstr[i]] = p1++;
            }
            if (!m2[pattern[i]]) {
                m2[pattern[i]] = p2++;
            }
            if (m1[vstr[i]] != m2[pattern[i]]) return false;
        }
        return true;
    }
};

// Solution
// Split the string
// Create a hash map -- using int as the common value type