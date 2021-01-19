#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string generateTheString(int n) {
        std::string res(n, 'a');

        if (n % 2 == 0) {
            int p = n / 2;
            if (p % 2 == 0) {
                p--;
            }
            for (int i = 0; i < p; i++) {
                res[i] = 'b';
            }
        }
        return res;
    }
};

int main() {
    vector<int> testCases { 4, 2, 7 };
    for (auto &testCase: testCases) {
        cout << Solution().generateTheString(testCase) << endl;
    }
    return 0;
}
