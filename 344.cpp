// Write a function that reverses a string. The input string is given as an array of characters char[].
// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
// You may assume all the characters consist of printable ascii characters.

#include <vector> 
using namespace std; 

class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        int l = s.size();
        for (int i = 0; i < l / 2; ++i) {
            temp = s[i];
            s[i] = s[l - 1 - i];
            s[l - 1 - i] = temp;
        }
    }
};