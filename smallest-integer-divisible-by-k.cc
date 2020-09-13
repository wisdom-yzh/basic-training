#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0) {
            return -1;
        }
        int count = 1;
        int m = 1 % K;
        while (m != 0) {
            m = (10 * m + 1) % K;
            count++;
        }

        return count;
    }
};

int main() {
    vector<int> testCases { 1, 2, 3 };
    for (auto &testCase: testCases) {
        cout << Solution().smallestRepunitDivByK(testCase) << endl;
    }
    return 0;
}
