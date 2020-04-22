// Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

#include <vector> 
#include <cstdlib> 
#include <cmath> 
using namespace std; 

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size(); 
        if (n < k) exit(0);
        vector<int> ans;
        int count = n, i = 0, j = n - 1;
        while (count > k) {
            if (abs(x - arr[i]) <= abs(x - arr[j])) {
                count --;
                j--;
            }
            else {
                count --;
                i++;
            }
        }
        for (int _ = i; _ <= j; _++)
            ans.push_back(arr[_]);
        return ans;
    }
};

//Solution
// two pointers