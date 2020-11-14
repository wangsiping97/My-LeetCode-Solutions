// Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.
// You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
// Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
// For the last line of text, it should be left justified and no extra space is inserted between words.

// Note:
// A word is defined as a character sequence consisting of non-space characters only.
// Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
// The input array words contains at least one word.

#include <string> 
using namespace std; 

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        int count = 0;
        int pre = 0, last;
        vector<string> ans;
        if (n == 0) return ans;
        for (int i = 0; i < n; ++i) {
            int l = words[i].length();
            count += l + 1;
            if (count > maxWidth + 1) {
                string str = helper(words, pre, i - 1, count - l - 1, maxWidth + 1);
                ans.push_back(str);
                count = l + 1;
                pre = i;
                last = i - 1;
            }
        }
        string last_line = "";
        for (int i = last + 1; i < n - 1; ++i) {
            last_line += words[i];
            last_line += " ";
        }
        last_line += words[n - 1];
        int last_length = last_line.length();
        for (int i = 0; i < maxWidth - last_length; ++i) last_line += " ";
        ans.push_back(last_line);
        return ans;
    }
    string helper(vector<string>& words, int start, int end, int length, int maxWidth) {
        string res = "";
        int countSpaces = maxWidth - length;
        if (end == start) {
            res += words[start];
            for (int i = 0; i < countSpaces; ++i) res += " ";
            return res;
        }
        int min = countSpaces / (end - start);
        int left = countSpaces % (end - start);
        for (int i = start; i < end; ++i) {
            res += words[i];
            if (i - start < left) res += " ";
            for (int j = 0; j <= min; ++j) res += " ";
        }
        res += words[end];
        return res;
    }
};