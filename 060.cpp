// The set [1,2,3,...,n] contains a total of n! unique permutations.
// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

#include <iostream> 
#include <string>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        string str;
        str.clear();
        for (int i = 1; i <= n; i++) {
            str.push_back(i + '0');
        }
        int p = 0;
        while (p < k) {
            next_permutation(str.begin(), str.end());
            p++;
        }
        return str;
    }
};