// Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.

// Example 1:
// Input: 12
// Output: 21

// Example 2:
// Input: 21
// Output: -1

#include <string> 
#include <vector> 
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> tail;
        tail.clear();
        int temp;
        while (n) {
            temp = n % 10;
            n /= 10;
            if (tail.empty() || temp >= tail.back())
                tail.push_back(temp);
            else 
                break;
        }
        int sz = tail.size();
        bool flag = false;
        for (int i = 0; i < sz; ++i) {
            if (tail[i] > temp) {
                int a = tail[i];
                tail[i] = temp;
                temp = a;
                flag = true;
                break;
            }
        }
        if (flag == false) return -1;
        n = n * 10 + temp;
        for (int i = 0; i < sz; ++i) {
            if (n < 214748364) 
                n = n * 10 + tail[i];
            else if (n == 214748364 && tail[i] <= 7)
                n = n * 10 + tail[i];
            else {
                return -1;
            }
        }
        return n;
    }
};