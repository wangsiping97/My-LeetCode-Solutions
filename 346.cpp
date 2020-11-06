// Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

#include <cmath> 
#include <queue> 
using namespace std;

class MovingAverage {
public:
    queue<int> q;
    double sum;
    int size;
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sum = 0;
        this->size = size;
    }
    
    double next(int val) {
        q.push(val);
        sum += val;
        if (q.size() <= size) {
            return sum / q.size();
        } else {
            sum -= q.front();
            q.pop();
            return sum / size;
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */