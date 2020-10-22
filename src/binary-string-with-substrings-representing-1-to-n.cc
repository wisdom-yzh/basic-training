#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool queryString(string S, int N) {
        int maxBits = this->getMaxBits(N);

        if (N == 0) {
            return true;
        }

        vector<bool> dict(N + 1, false);
        int count = 0;

        for (int i = 0; i < S.size() - maxBits + 1; i++) {
            int value = 0;
            for (int j = 0; j < maxBits; j++) {
                if (S[i + j] == '1') {
                    value += 1;
                }

                if (value != 0 && value <= N && !dict[value]) {
                    dict[value] = true;
                    count++;
                }

                if (count == N) {
                    return true;
                }
                value <<= 1;
            }
        }

        return false;
    }

    int getMaxBits(int N) {
        int bits = 0;
        while (N > 0) {
            bits++;
            N >>= 1;
        }
        return bits;
    }
};

int main() {
    vector<pair<string, int>> testCases {
        { "0110", 3 },
        { "0110", 4 },
        { "10010111100001110010", 10}
    };
    for (auto &testCase: testCases) {
        cout << boolalpha << Solution().queryString(testCase.first, testCase.second) << endl;
    }
    return 0;
}
