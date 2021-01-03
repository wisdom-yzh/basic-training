#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        if (n == 1) {
            return { 1 };
        }
        vector<int> res;
        int s = n % 2 == 0 ? -n / 2 : (1 - n) / 2;
        for (int i = s; i <= -s; i++) {
            if (n % 2 == 0 && i == 0) {
                continue;
            }
            res.push_back(i);
        }
        return res;
    }
};

int main() {
    vector<int> testCases {
        5,
        3,
        1
    };
    for (auto &testCase: testCases) {
        for (auto &x: Solution().sumZero(testCase)) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}
