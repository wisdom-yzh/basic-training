#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSteps (int num) {
        int res = 0;
        while (num != 0) {
            res++;
            if (num % 2 == 0) {
                num /= 2;
            } else {
                num--;
            }
        }
        return res;
    }
};

int main() {
    vector<int> testCases {
        14,
        8,
        123
    };
    for (auto &testCase: testCases) {
        cout << Solution().numberOfSteps(testCase) << endl;
    }
    return 0;
}
