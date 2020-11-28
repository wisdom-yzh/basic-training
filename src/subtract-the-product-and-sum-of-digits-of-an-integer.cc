#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        const auto &s = std::to_string(n);
        int sum = 0, product = 1;

        for (auto &ch: s) {
            int num = static_cast<int>(ch - '0');
            sum += num;
            product *= num;
        }

        return product - sum;
    }
};

int main() {
    vector<int> testCases { 234, 4421 };
    for (auto &n: testCases) {
        cout << Solution().subtractProductAndSum(n) << endl;
    }
    return 0;
}
