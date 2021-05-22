#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        for (int j = 2; j <= n; j++) {
            for (int i = 1; i < j; i++) {
                if (gcd(j, i) == 1) {
                    res.push_back(to_string(i) + "/" + to_string(j));
                }
            }
        }
        return res;
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};

int main() {
    vector<int> testCases { 2, 3, 4, 1 };
    for (auto &testCase: testCases) {
        for (auto &s: Solution().simplifiedFractions(testCase)) {
            cout << s << '\t';
        }
        cout << endl;
    }
    return 0;
}
