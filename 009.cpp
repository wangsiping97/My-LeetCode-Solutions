// Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
// Example 1:
// Input: 121
// Output: true
// Example 2:
// Input: -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:
// Input: 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
// Follow up:
// Coud you solve it without converting the integer to a string?

#include <iostream> 
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return 0;
        else {
            vector<int> v1;
            while (x) {
                int pop = x % 10;
                x /= 10;
                v1.push_back(pop);
            }
            int i = 0;
            while (i < v1.size() / 2 && v1[i] == v1[v1.size() - i - 1]) {
                i++;
            }
            return i == v1.size() / 2;
        }
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome(121) << endl;
    cout << s.isPalindrome(-121) << endl;
    cout << s.isPalindrome(10) << endl;
    return 0;
}