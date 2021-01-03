#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            if (!hasZero(i) && !hasZero(n - i)) {
                return { i, n - i };
            }
        }
        return {0, 0};
    }

    bool hasZero(int x) {
        while (x != 0) {
            if (x % 10 == 0) {
                return true;
            }
            x /= 10;
        }
        return false;
    }
};

int main() {
    vector<int> testCases {
        2,
        11,
        10000,
        69,
        1010,
    };
    for (auto &testCase: testCases) {
        for (auto &x: Solution().getNoZeroIntegers(testCase)) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}
