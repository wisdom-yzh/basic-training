#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    double soupServings(int N) {
        if (N > 5000) return 1.0;
        std::unordered_map<uint64_t, double> P;
        return recursiveServing(P, N, N, N);
    }

    double recursiveServing(std::unordered_map<uint64_t, double> &P, int N, int A, int B) {
        if (A <= 0 && B <= 0) {
            return 0.5;
        }

        if (A <= 0 && B > 0) {
            return 1;
        }

        if (A > 0 && B <= 0) {
            return 0;
        }

        auto iter = P.find(A * N + B);
        if (iter != P.end()) {
            return iter->second;
        }

        double p = 0.25 * recursiveServing(P, N, A - 100, B) +
            0.25 * recursiveServing(P, N, A - 75, B - 25) +
            0.25 * recursiveServing(P, N, A - 50, B - 50) +
            0.25 * recursiveServing(P, N, A - 25, B - 75);
        P.emplace(A * N + B, p);
        return p;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int N = stringToInteger(line);

        double ret = Solution().soupServings(N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
