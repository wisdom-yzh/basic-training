#include <iostream>
#include <memory>
#include <vector>
#include <iterator>
using namespace std;

class FrontMiddleBackQueue {
public:
    vector<int> q;

    FrontMiddleBackQueue() {}

    void pushFront(int val) {
        q.emplace(q.begin(), val);
    }

    void pushMiddle(int val) {
        q.emplace(next(q.begin(), q.size() / 2), val);
    }

    void pushBack(int val) {
        q.push_back(val);
    }

    int popFront() {
        if (q.empty()) {
            return -1;
        }
        int res = q.front();
        q.erase(q.begin());
        return res;
    }

    int popMiddle() {
        if (q.empty()) {
            return -1;
        }
        auto iter = next(q.begin(), (q.size() - 1) / 2);
        int res = *iter;
        q.erase(iter);
        return res;
    }

    int popBack() {
        if (q.empty()) {
            return -1;
        }
        int res = q.back();
        q.pop_back();
        return res;
    }
};

int main() {
    auto obj = std::unique_ptr<FrontMiddleBackQueue>(new FrontMiddleBackQueue());
    obj->pushFront(1);
    obj->pushBack(2);
    obj->pushMiddle(3);
    obj->pushMiddle(4);
    cout << obj->popFront() << ' '
         << obj->popMiddle() << ' '
         << obj->popMiddle() << ' '
         << obj->popBack() << ' '
         << obj->popFront() << ' ';
}
