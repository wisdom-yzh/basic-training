#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        uint32_t a0 = 0, a1 = 1, a2 = 1;

        for (int i = 0; i < n; i++) {
            uint32_t t = a0 + a1 + a2;
            a0 = a1;
            a1 = a2;
            a2 = t;
        }

        return static_cast<int>(a0);
    }
};

int main() {
    vector<int> testCases({ 4, 10, 25, 37 });

    for (auto &testCase: testCases) {
        cout << Solution().tribonacci(testCase) << endl;
    }

    return 0;
}
