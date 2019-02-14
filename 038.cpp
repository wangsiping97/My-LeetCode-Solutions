// The count-and-say sequence is the sequence of integers with the first five terms as following:
// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.

// Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
// Note: Each term of the sequence of integers will be represented as a string. 

// Example 1:
// Input: 1
// Output: "1"

// Example 2:
// Input: 4
// Output: "1211"

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string initial = "1";
        string next;
        int i;
        while (n != 1) {
            for (i = 0; i < initial.length(); ) {
                int j = i + 1;
                while (j < initial.length() && initial[j] == initial[i]) {
                    j++;
                }
                next.append(1, j - i + '0');
                next.append(1, initial[i]);
                i = j;
            } 
            initial = next;
            next.clear();
            n--;
        }
        return initial;
    }
};

int main() {
    Solution s;
    for (int n = 1; n < 6; cout << s.countAndSay(n) << endl, n++);
    return 0;
}