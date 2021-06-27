#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string thousandSeparator(int n) {
        string sn = to_string(n), res;

        int start = 0;
        for (int i = 0; i < sn.size(); i++) {
            if (start == 3) {
                start = 0;
                res.push_back('.');
            }
            start++;
            res.push_back(sn[sn.size() - 1 - i]);
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    std::vector<int> testCases {
        987,
        1234,
        123456789,
        0
    };

    for (auto &testCase: testCases) {
        cout << Solution().thousandSeparator(testCase) << endl;
    }
    return 0;
}
