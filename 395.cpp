// Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

#include <string> 
using namespace std; 

class Solution {
public:
    int count[128];
    int dvd_conq(string s, int k, int start, int end) {
        memset (count, 0, 128 * 4);
        for (int i = start; i <= end; ++i) {
            count[s[i]]++;
        }
        // Sliding windows
        while (start <= end && count[s[start]] < k)
            start++;
        while (end >= start && count[s[end]] < k)
            end--;
        if (end - start + 1 < k)
            return 0;

        // Divide & Conquer
        for (int i = start; i < end; ++i) {
            if (count[s[i]] < k)
                return max(dvd_conq(s, k, start, i - 1), dvd_conq(s, k, i + 1, end));
        }
        return end - start + 1;
    }
    int longestSubstring(string s, int k) {
        int l = s.length();
        return dvd_conq(s, k, 0, l - 1);
    }
};