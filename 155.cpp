// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.

#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> origin_stack;
    stack<int> min_stack; // Monotone Stack
    MinStack() {}
    
    void push(int val) {
        origin_stack.push(val);
        if (min_stack.empty()) {
            min_stack.push(val);
        } else {
            int top = min_stack.top();
            if (val <= top) {
                min_stack.push(val);
            }
        }
    }
    
    void pop() {
        int top_origin = origin_stack.top();
        int min = min_stack.top();
        origin_stack.pop();
        if (min == top_origin) {
            min_stack.pop();
        }
    }
    
    int top() {
        return origin_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */