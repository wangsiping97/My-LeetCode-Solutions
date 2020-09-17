// Implement the following operations of a queue using stacks.

// push(x) -- Push element x to the back of queue.
// pop() -- Removes the element from in front of queue.
// peek() -- Get the front element.
// empty() -- Return whether the queue is empty.

#include <stack>
using namespace std;

class MyQueue
{
private:
    stack<int> queue;
    stack<int> temp; // peek of the queue
public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        if (queue.empty())
            temp.push(x);
        queue.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        temp.pop();
        while (!queue.empty())
        {
            temp.push(queue.top());
            queue.pop();
        }
        int val = temp.top();
        temp.pop();
        if (temp.empty())
            return val;
        int newPeek = temp.top();
        while (!temp.empty())
        {
            queue.push(temp.top());
            temp.pop();
        }
        temp.push(newPeek);
        return val;
    }

    /** Get the front element. */
    int peek()
    {
        return temp.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return queue.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */