#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int sum = 0, diff = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'L') {
                diff--;
            } else {
                diff++;
            }

            if (diff == 0) {
                sum++;
            }
        }
        return sum;
    }
};

int main() {
    vector<string> testCases {
        "RLRRLLRLRL",
        "RLLLLRRRLR",
        "LLLLRRRR",
        "RLRRRLLRLL"
    };
    for (auto &testCase: testCases) {
        cout << Solution().balancedStringSplit(testCase) << endl;
    }
    return 0;
}
