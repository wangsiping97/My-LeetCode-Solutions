// Given a nested list of integers, implement an iterator to flatten it.
// Each element is either an integer, or a list -- whose elements may also be integers or other lists.

#include <vector> 
#include <stack> 
#include <cstdlib> 
using namespace std; 

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    stack<NestedInteger> v;
    int val;
    NestedIterator(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();
        for (int i = n - 1; i >= 0; --i) {
            v.push(nestedList[i]);
        }
    }
    
    int next() {
        v.pop();
        return val;
    }
    
    bool hasNext() {
        if (v.empty()) return false;
        NestedInteger top = v.top();
        if (top.isInteger()) {
            val = top.getInteger();
            return true;
        }
        int n = top.getList().size();
        v.pop();
        for (int i = n - 1; i >= 0; --i) {
            v.push(top.getList()[i]);
        }
        return hasNext();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */