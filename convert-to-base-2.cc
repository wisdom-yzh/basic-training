#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    string baseNeg2(int N) {
        if (N == 0) {
            return "0";
        }

        string ans = "";
        while (N != 0) {
            ans = to_string(abs(N % 2)) + ans;
            if (abs(N) % 2) {
                if (N < 0) {
                    N = N / -2 + 1;
                } else {
                    N = N / -2;
                }
            } else {
                N = N / -2;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> testCases { 2, 3, 4};
    for (const auto &testCase: testCases) {
        cout << Solution().baseNeg2(testCase) << endl;
    }
    return 0;
}
