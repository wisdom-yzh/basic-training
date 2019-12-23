#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

class Solution {
public:
    static vector<int> cache;

    int minSteps(int n) {
        if (n == 1) {
            return 0;
        }

        if (cache[n] != -1) {
            return cache[n];
        }

        int minValue = n;
        for (int i = 2, tail = (n >> 1); i <= tail; i++) {
            if ((n % i) == 0) {
                minValue = std::min(minValue, minSteps(n / i) + i);
            }
        }

        cache[n] = minValue;
        return cache[n];
    }
};

vector<int> Solution::cache(1001, -1);

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().minSteps(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
