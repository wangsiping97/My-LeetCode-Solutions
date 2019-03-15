// Given a collection of distinct integers, return all possible permutations.

// Example:

// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

#include <iostream> 
#include <vector>
using namespace std;

class Solution {
public:
    vector< vector<int> > permute(vector<int>& nums) {
        vector< vector<int> > res;
        sort(nums.begin(), nums.end());
        do {
            res.push_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));
        return res;
    }
};