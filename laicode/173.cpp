// Given a string, replace adjacent, repeated characters with the character followed by the number of repeated occurrences. If the character does not has any adjacent, repeated occurrences, it is not changed.
// Assumptions
// The string is not null
// The characters used in the original string are guaranteed to be ‘a’ - ‘z’

#include <string> 
using namespace std; 

class Solution {
    public:
    string compress(string input) {
        // write your solution here
        string ans; 
        if (input == "") return ans;
        int l = input.length();
        ans += input[0];
        int count = 1;
        for (int i = 1; i < l; ++i) {
            if (input[i] != input[i - 1]) {
                if (count > 1) ans += to_string(count);
                count = 1;
                ans += input[i];
            } 
            else if (i == l - 1){
                count++;
                ans += to_string(count);
            }
            else {
                count++;
            }
        }
        return ans; 
    }
};
