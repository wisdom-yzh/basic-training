#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    const static int MODULO = 1e9 + 7;

    static vector<vector<int>> memo;
    static vector<vector<int>> mapping;

    int knightDialer(int N) {
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            sum = (sum + dialer(N, i)) % MODULO;
        }
        return sum;
    }

    int dialer(int N, int number) {
        if (memo[N][number] != -1) {
            return memo[N][number];
        }

        if (N == 1) {
            memo[N][number] = 1;
        } else {
            int sum = 0;
            for (const auto &nextNum: mapping[number]) {
                sum = (sum + dialer(N - 1, nextNum)) % MODULO;
            }
            memo[N][number] = sum;
        }

        return memo[N][number];
    }
};

vector<vector<int>> Solution::memo(5001, vector<int>(10, -1));

vector<vector<int>> Solution::mapping {
    { 4, 6 },
    { 6, 8 },
    { 7, 9 },
    { 4, 8 },
    { 0, 3, 9 },
    {},
    { 0, 1, 7 },
    { 2, 6 },
    { 1, 3 },
    { 2, 4 },
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int N = stringToInteger(line);

        int ret = Solution().knightDialer(N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
