#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        num.push(x);
        if (minNum.empty() || x <= minNum.top()) {
            minNum.push(x);
        }
    }
    
    void pop() {
        if (num.top() == minNum.top()) {
            minNum.pop();
        }
        num.pop();
    }
    
    int top() {
        return num.top();
    }
    
    int getMin() {
        return minNum.top();
    }

private:
    stack<int> num, minNum;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
int main () {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin();   // --> Returns -3.
    minStack.pop();
    cout << minStack.top();      // --> Returns 0.
    cout << minStack.getMin();   // --> Returns -2.
    return 0;
}
