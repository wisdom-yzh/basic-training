#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    constexpr static int DIRECTION[8][2] = {
        { 2, 1 }, { 2, -1 }, { 1, 2 }, { -1, 2 },
        { -2, -1 }, { -2, 1 }, { -1, -2 }, { 1, -2 }
    };
    using arr2d = vector<vector<double>>;
    using arr3d = vector<arr2d>;

    double knightProbability(int N, int K, int r, int c) {
        arr3d arr(K, arr2d(N, vector<double>(N, -1)));

        return this->recursiveKnightProbability(arr, N, K, r, c);
    }

    double recursiveKnightProbability(arr3d &arr, int N, int K, int r, int c) {
        if (r < 0 || r >= N || c < 0 || c >= N) {
            return 0;
        }
        if (K == 0) {
            return 1;
        }

        if (arr[K - 1][r][c] != -1) {
            return arr[K - 1][r][c];
        }

        arr[K - 1][r][c] = 0;
        for (const auto &delta: Solution::DIRECTION) {
            arr[K - 1][r][c] += this->recursiveKnightProbability(arr, N, K - 1, r + delta[1], c + delta[0]);
        }
        arr[K - 1][r][c] /= 8;

        return arr[K - 1][r][c];
    }
};

constexpr int Solution::DIRECTION[8][2];

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int N = stringToInteger(line);
        getline(cin, line);
        int K = stringToInteger(line);
        getline(cin, line);
        int r = stringToInteger(line);
        getline(cin, line);
        int c = stringToInteger(line);

        double ret = Solution().knightProbability(N, K, r, c);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
