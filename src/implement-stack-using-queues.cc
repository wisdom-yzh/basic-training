#include <queue>
#include <iostream>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        p = &q1;
        q = &q2;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        p->push(x);
        topValue = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = topValue;
        while (p->size() > 1) {
            topValue = p->front();
            q->push(p->front());
            p->pop();
        }
        p->pop();
        std::swap(p, q);
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return topValue;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return p->empty();
    }

private:
    std::queue<int> q1, q2;
    std::queue<int> *p, *q;
    int topValue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
int main() {
    MyStack obj;
    obj.push(1);
    obj.push(2);
    int p2 = obj.pop();
    int p3 = obj.top();
    bool p4 = obj.empty();
    
    cout << p2 << p3 << boolalpha << p4;
}


