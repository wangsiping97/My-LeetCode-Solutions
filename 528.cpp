// Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

// Note:
// 1 <= w.length <= 10000
// 1 <= w[i] <= 10^5
// pickIndex will be called at most 10000 times.

#include <vector> 
#include <cstdlib> 
#include <ctime> 
using namespace std; 

class Solution {
public:
    int sum;
    vector<int> arr;
    Solution(vector<int>& w) {
        sum = 0;
        arr = w;
        int n = w.size();
        for (int i = 0; i < n; ++i) {
            arr[i] += sum;
            sum += w[i];
        }
    }
    
    int pickIndex() {
        int rad = rand() % sum + 1;
        int n = arr.size();
        int start = 0, end = n - 1;
        int mid;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (rad > arr[mid]) start = mid + 1;
            else {
                if (mid == 0) return 0;
                else if (rad > arr[mid - 1]) return mid;
                else end = mid;
            }
        }
        return mid;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

// Solution
// 这个题很巧妙，我是想不出来的。做法是把概率分布函数转化为累计概率分布函数。然后通过随机数，进行二分查找。
// 比如，输入是[1,2,3,4]，那么概率分布是[1/10, 2/10, 3/10, 4/10]，累积概率分布是[1/10, 3/10, 6/10, 10/10].总和是10。如果我们产生一个随机数，在1~10之中，然后判断这个数字在哪个区间中就能得到对应的索引。