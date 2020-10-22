#include <iostream>
#include <vector>
using namespace std;

class RecentCounter {
public:
    RecentCounter() {

    }

    int ping(int t) {
        arr.push_back(t);
        if (t <= 3000) {
            return arr.size();
        }

        int i = arr.size() - 1;
        while (i >= 0 && arr[i] >= t - 3000) {
            i--;
        }
        return arr.size() - i;
    }

private:
    std::vector<int> arr;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 */
int main() {
    RecentCounter* obj = new RecentCounter();
    cout << obj->ping(123);
    return 0;
}
