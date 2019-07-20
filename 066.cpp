// Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
// You may assume the integer does not contain any leading zero, except the number 0 itself.

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits.back() += 1;
        int n = digits.size();
        for (int i = n-1; i > 0; i--) {
            if (digits[i] == 10) {
                digits[i] -= 10;
                digits[i-1] += 1;
            }
            else break;
        }
        if (digits[0] == 10) {
            vector<int> ans;
            ans.push_back(1);
            for (int i = 0; i < n; i++) {
                ans.push_back(0);
            }
            return ans;
        }
        return digits;
    }
};