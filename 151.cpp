// Given an input string, reverse the string word by word.

#include <string> 
#include <sstream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans;
        istringstream iss(s);
        string temp;
        while (getline(iss, temp, ' ')) {
            if (!temp.empty()) {
                temp.append(1, ' ');
                ans.insert(0, temp);
            }
        }
        ans.pop_back();
        return ans;
    }
};