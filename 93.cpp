// Given a string containing only digits, restore it by returning all possible valid IP address combinations.
// A valid IP address consists of exactly four integers (each integer is between 0 and 255) separated by single points.

#include <vector> 
#include <string> 
#include <cstdlib> 
using namespace std; 

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int l = s.length();
        if (l < 4) return ans;
        for (int i = 1; i < l; ++i) {
            string s1 = s.substr(0, i);
            if (atoi(s1.data()) > 255) break;
            if (s1[0] == '0' && i > 1) break;
            for (int j = i + 1; j < l; ++j) {
                string s2 = s.substr(i, j - i);
                if (atoi(s2.data()) > 255) break;
                if (s2[0] == '0' && j - i > 1) continue;
                for (int k = j + 1; k < l; ++k) {
                    string s3 = s.substr(j, k - j);
                    if (atoi(s3.data()) > 255) break;
                    if (s3[0] == '0' && k - j > 1) continue;
                    string s4 = s.substr(k);
                    if (s4.length() == 0) break;
                    if (atoi(s4.data()) > 255 || (s4[0] == '0' && s4.length() > 1) || s4.length() > 3) continue;
                    string thisans = "";
                    thisans = s1 + "." + s2 + "." + s3 + "." + s4;
                    ans.push_back(thisans);
                }
            }
        }
        return ans;
    }
};