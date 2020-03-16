// You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.
// The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

#include <string> 
using namespace std; 

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int arr[128];
        memset(arr, 0, 128 * 4);
        for (int i = 0; i < S.length(); ++i) {
            arr[S[i]]++;
        }
        int sum = 0;
        for (int j = 0; j < J.length(); ++j) {
            sum += arr[J[j]];
        }
        return sum;
    }
};

// Solution
// 1. Using bucket to count out the times each word appears in S.
// 2. Sum up the values in arr[char] for char in J. 