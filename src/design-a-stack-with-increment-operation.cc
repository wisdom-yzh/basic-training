#include <iostream>
#include <vector>
using namespace std;

class CustomStack {
private:
    vector<int> arr;
    int p;

public:
    CustomStack(int maxSize) {
        arr.assign(maxSize, 0);
        p = 0;
    }

    void push(int x) {
        if (p == arr.size()) {
            return;
        }
        arr[p++] = x;
    }

    int pop() {
        if (p == 0) {
            return -1;
        }
        return arr[--p];
    }

    void increment(int k, int val) {
        int m = std::min(k, p);
        for (int i = 0; i < m; i++) {
            arr[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 */
int main() {
    CustomStack customStack(3);
    customStack.push(1);                          // 栈变为 [1]
    customStack.push(2);                          // 栈变为 [1, 2]
    customStack.pop();                            // 返回 2 --> 返回栈顶值 2，栈变为 [1]
    customStack.push(2);                          // 栈变为 [1, 2]
    customStack.push(3);                          // 栈变为 [1, 2, 3]
    customStack.push(4);                          // 栈仍然是 [1, 2, 3]，不能添加其他元素使栈大小变为 4
    customStack.increment(5, 100);                // 栈变为 [101, 102, 103]
    customStack.increment(2, 100);                // 栈变为 [201, 202, 103]
    customStack.pop();                            // 返回 103 --> 返回栈顶值 103，栈变为 [201, 202]
    customStack.pop();                            // 返回 202 --> 返回栈顶值 202，栈变为 [201]
    customStack.pop();                            // 返回 201 --> 返回栈顶值 201，栈变为 []
    customStack.pop();                            // 返回 -1 --> 栈为空，返回 -1
    return 0;
}
