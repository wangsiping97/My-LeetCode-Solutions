// Implement the following operations of a stack using queues.
// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// empty() -- Return whether the stack is empty.

#include <queue> 
using namespace std; 

class MyStack {
public:
    queue<int> stack; 

    /** Initialize your data structure here. */
    MyStack() {
        stack.empty();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        stack.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> temp; 
        while (stack.size() > 1) {
            temp.push(stack.front());
            stack.pop();
        }
        int val = stack.front();
        stack.pop();
        while (!temp.empty()) {
            stack.push(temp.front());
            temp.pop();
        }
        return val; 
    }
    
    /** Get the top element. */
    int top() {
        return stack.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return stack.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */