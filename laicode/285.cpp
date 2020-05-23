// Given a string, return the longest contiguous substring that contains exactly k type of characters.
// Return null if there does not exist such substring.

// Assumptions:
// The given string is not null and guaranteed to have at least k different characters.
// k > 0.

#include <string> 
#include <iostream>
using namespace std; 

class Solution {
 public:
  string longest(string input, int k) {
    // write your solution here
    int l = input.length();
    int start = 0, end = 0, count = 0; 
    int bucket[128];
    memset(bucket, 0, 128 * 4);
    while (end < l) {
        if (bucket[input[end] - ' '] == 0) count++;
        if (count == k + 1) break;
        bucket[input[end] - ' ']++;
        end++;
    }
    if (count < k) return NULL; 
    if (count == k) return input;
    // now end is at the first of the (k+1)th character.
    int max_start = start, max_end = end;
    while (start < l) {
        while (start < l && --bucket[input[start++] - ' '] > 0);
        count = 0;
        while (end < l) {
            if (bucket[input[end] - ' '] == 0) count++;
            if (count == 2) break;
            bucket[input[end] - ' ']++;
            end++;
        }
        if (end - start > max_end - max_start) {
            max_end = end;
            max_start = start;
        }
        if (end == l) break;
    }
    return input.substr(max_start, max_end - max_start);
  }
};
