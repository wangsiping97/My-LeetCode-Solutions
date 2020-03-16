// Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.
// Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.

#include <string> 
#include <sstream> 
#include <vector> 
#include <map> 
using namespace std; 

class Solution {
public:
    vector<string> makeVec(string paragraph) {
        vector<string> vstr;
        vstr.clear();
        int start = 0, len = 0;
        for (int i = 0; i < paragraph.length(); ++i) {
            if (paragraph[i] >= 'A' && paragraph[i] <= 'Z') {
                paragraph[i] -= 'A' - 'a';
                len++;
            }
            else if (paragraph[i] >= 'a' && paragraph[i] <= 'z') {
                len++;
            }
            else {
                vstr.push_back(paragraph.substr(start, len));
                start += len;
                len = 0;
            }
        }
        return vstr;
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        vector<string> vstr = makeVec(paragraph);
        map<string, int> m;
        for (int i = 0; i < vstr.size(); ++i) {
                m[vstr[i]]++;
        }
        for (int j = 0; j < banned.size(); ++j) {
            m[banned[j]] = -1;
        }
        m[""] = -1;
        int maxVal = 0;
        string ans;
        map<string, int>::iterator iter;
        for (iter = m.begin(); iter != m.end(); iter++) {
            if (iter->second > maxVal) {
                maxVal = iter->second;
                ans = iter->first;
            }
        }
        return ans;
    }
};

// Solution 
// 1. Split the paragraph -- two pointers or istringstream
// 2. Count the words out -- map<string, int>
// 3. filter out the not banned words 
// 4. Find out the maximum value and its key