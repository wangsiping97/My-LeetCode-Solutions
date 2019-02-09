// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:
// Input: ["flower","flow","flight"]
// Output: "fl"

// Example 2:
// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

// Note:
// All given inputs are in lowercase letters a-z.

#include <iostream> 
#include <vector> 
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty() == 1) return "";
        else {
            int min = strs[0].length();
            for (int i = 1; i < strs.size(); i++) {
                if (min > strs[i].length())
                    min = strs[i].length();
                for (int j = 0; j < min; j++) {
                    if (strs[i][j] != strs[i - 1][j]) {
                        min = j;
                        break;
                    }
                }
            }
            return strs[0].substr(0, min);
        }
    }
};

int main() {
    Solution s;
    string str1 = "flower";
    string str2 = "flow";
    string str3 = "flight";
    vector<string> strs;
    strs.push_back(str1);
    strs.push_back(str2);
    strs.push_back(str3);
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}