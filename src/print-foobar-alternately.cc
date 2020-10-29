#include <functional>
#include <thread>
#include <mutex>
#include <vector>
#include <iostream>
using namespace std;

class FooBar {
private:
    int n;
    std::mutex mFoo, mBar;

public:
    FooBar(int n) {
        this->n = n;
        mBar.lock();
    }

    void foo() {
        for (int i = 0; i < n; i++) {
            mFoo.lock();
            cout << "foo" << endl;
            mBar.unlock();
        }
    }

    void bar() {
        for (int i = 0; i < n; i++) {
            mBar.lock();
            cout << "bar" << endl;
            mFoo.unlock();
        }
    }
};

int main() {
    return 0;
}
