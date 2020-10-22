#include <vector>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class Solution {
public:
    static const int64_t MOD_MAX = 1000000007;

    int numPrimeArrangements(int n) {
        int primeNum = 0;
        for (int i = 2; i <= n; i++) {
            if (isPrime(i)) {
                primeNum++;
            }
        }

        return static_cast<int>((factorial(primeNum) * factorial(n - primeNum)) % MOD_MAX);
    }

    bool isPrime(int n) {
        int sqrtn = static_cast<int>(std::sqrt(n));
        for (int i = 2; i <= sqrtn; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    int64_t factorial(int n) {
        int64_t result = 1;
        for (int64_t i = 1; i <= n; i++) {
            result = (result * i) % MOD_MAX;
        }
        return result;
    }
};

int main() {
    vector<int> testCases { 5, 100 };
    for (auto &testCase: testCases) {
        cout << Solution().numPrimeArrangements(testCase) << endl;
    }
    return 0;
}
