#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class StockSpanner {
public:
    StockSpanner() {

    }

    int next(int price) {
        if (s.empty()) {
            s.push({ price, 1 });
            return 1;
        }

        int value = 1;
        while (!s.empty() && price >= s.top().first) {
            value += s.top().second;
            s.pop();
        }
        s.push({ price, value });
        return value;
    }

private:
    std::stack<std::pair<int, int>> s;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
int main() {
    StockSpanner* obj = new StockSpanner();
    vector<int> s { 100, 100, 80, 60, 70, 60, 75, 85, 105 };
    for (const auto &i: s) {
        cout << obj->next(i) << endl;
    }
    return 0;
}
