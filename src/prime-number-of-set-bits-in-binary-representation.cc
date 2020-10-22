#include <iostream>
#include <array>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    static array<int, 1000001> primes;

    int countPrimeSetBits(int L, int R) {
        int count = 0;
        for (int i = L; i <= R; i++) {
            if (isPrime(getBits(i))) {
                count++;
            }
        }
        return count;
    }

    int getBits(int num) {
        int bits = 0;
        while (num != 0) {
            num &= (num - 1);
            bits++;
        }
        return bits;
    }

    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }

        if (primes[n] != -1) {
            return primes[n] == 1;
        }

        for (int i = 2, s = std::sqrt(n); i <= s; i++) {
            if ((n % i) == 0) {
                primes[n] = 0;
                return false;
            }
        }

        primes[n] = 1;
        return true;
    }
};

array<int, 1000001> Solution::primes = ([]() {
    array<int, 1000001> tmp;
    for (int i = 0; i < 1000001; i++) {
        tmp[i] = -1;
    }
    return tmp;
})();


int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int L = stringToInteger(line);
        getline(cin, line);
        int R = stringToInteger(line);

        int ret = Solution().countPrimeSetBits(L, R);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
