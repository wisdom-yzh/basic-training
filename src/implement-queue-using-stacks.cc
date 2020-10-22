#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        p = &s1;
        q = &s2;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (p->empty()) {
            topValue = x;
        }
        p->push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top = topValue;
        topValue = p->top();
        while (p->size() > 1) {
            topValue = p->top();
            q->push(topValue);
            p->pop();
        }
        p->pop();
        while (!q->empty()) {
            p->push(q->top());
            q->pop();
        }
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        return topValue;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return p->empty();
    }
private:
    stack<int> s1, s2, *p, *q;
    int topValue;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
int main() {
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    cout << queue.peek();  // returns 1
    cout << queue.pop();   // returns 1
    cout << queue.pop();   // returns 2
    cout << queue.pop();   // returns 3
    cout << boolalpha << queue.empty(); // returns true
    return 0;
}
