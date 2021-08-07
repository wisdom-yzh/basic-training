#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    static vector<string> S;

    char findKthBit(int n, int k) {
        return S[n - 1][k - 1];
    }
};

vector<string> Solution::S = [] {
    std::vector<string> S;

    S.push_back("0");
    for (int i = 1; i < 20; i++) {
        string prev = S[i - 1];
        for (auto &ch: prev) {
            ch = ch == '1' ? '0' : '1';
        }
        std::reverse(prev.begin(), prev.end());
        S.push_back(S[i - 1] + "1" + prev);
    }

    return S;
}();

int main() {
    vector<pair<int, int>> testCases {
        { 3, 1 },
        { 4, 11 },
        { 1, 1 },
        { 2, 3 },
    };
    for (auto &testCase: testCases) {
        cout << Solution().findKthBit(testCase.first, testCase.second)
             << endl;
    }
    return 0;
}
