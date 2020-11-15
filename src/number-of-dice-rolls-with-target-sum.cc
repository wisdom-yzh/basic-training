#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> memo;

    int numRollsToTarget(int d, int f, int target) {
        memo.assign(d + 1, vector<int>(target + 1, -1));
        return recursiveRoll(d, f, target);
    }

    int recursiveRoll(int d, int f, int target) {
        if (d == 0) {
            return target == 0 ? 1 : 0;
        }

        if (memo[d][target] != -1) {
            return memo[d][target];
        }

        int result = 0;
        for (int i = 1; i <= f; i++) {
            if (target >= i) {
                result = ((uint32_t)result + recursiveRoll(d - 1, f, target - i)) % MOD;
            }
        }

        memo[d][target] = result;
        return result;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int d = stringToInteger(line);
        getline(cin, line);
        int f = stringToInteger(line);
        getline(cin, line);
        int target = stringToInteger(line);

        int ret = Solution().numRollsToTarget(d, f, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
