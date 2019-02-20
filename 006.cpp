// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:
// string convert(string s, int numRows);

// Example 1:
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"

// Example 2:
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI" 
// Explanation:

// P     I    N
// A   L S  I G
// Y A   H R
// P     I

#include <iostream> 
#include <string> 
using namespace std; 

class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        if (numRows == 1) return s;
        int l = s.length();
        ans.reserve(l);
        int k = l / (numRows * 2 - 2);
        for (int j = 0; j < numRows; j++) {
            for (int i = 0; i < 2 *(k + 1); i++) {
                if (i % 2 == 0) {
                    if ((numRows * 2 - 2) * i / 2 + j < l)
                        ans.append(1, s[(numRows * 2 - 2) * i / 2 + j]);
                }
                else {
                    if (j != 0 && j != numRows - 1) {
                        if ((numRows * 2 - 2) * (i + 1) / 2 - j < l)
                            ans.append(1, s[(numRows * 2 - 2) * (i + 1) / 2 - j]);
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.convert("PAYPALISHIRING", 4) << endl;
    return 0;
}