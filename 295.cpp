// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

#include <vector>
#include <queue> 

using namespace std; 

class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> loq;
    priority_queue<int> highq;
    double median; 
    int n;
    
    MedianFinder() {
        median = 0;
        n = 0;
    }
    
    void addNum(int num) {
        n++;
        if (n == 1) {
            loq.push(num);
            highq.push(num);
            median = num;
            return;
        } 
        if (num >= median) {
            loq.push(num);
        } else {
            highq.push(num);
        }
        int balance = (n+1)/2;
        int loq_sz = loq.size();
        int highq_sz = highq.size();
        if (loq_sz > balance) loq.pop();
        else if (loq_sz < balance) loq.push(highq.top());
        if (highq_sz > balance) highq.pop();
        else if (highq_sz < balance) highq.push(loq.top());
        median = (double)(highq.top() + loq.top()) / 2;
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */