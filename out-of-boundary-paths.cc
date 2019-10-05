#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

const int MAX_RANGE = 1000000007;

class Solution {
public:
    vector<vector<vector<int>>> table;

    int findPaths(int m, int n, int N, int i, int j) {
        table = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(N, -1)));
        int64_t result = 0;
        for (int t = 1; t <= N; t++) {
            result += (int64_t)recursionFindPaths(m, n, t, i, j);
            result %= MAX_RANGE;
        }
        return result;
    }

    int recursionFindPaths(int m, int n, int N, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || N == 0) {
            return 0;
        }

        if (table[i][j][N - 1] != -1) {
            return table[i][j][N - 1];
        }

        int result;
        if (N == 1) {
            result = getOnePath(m, n, i, j);
        } else {
            result = ((int64_t)recursionFindPaths(m, n, N - 1, i + 1, j) +
                    (int64_t)recursionFindPaths(m, n, N - 1, i - 1, j) +
                    (int64_t)recursionFindPaths(m, n, N - 1, i, j + 1) +
                    (int64_t)recursionFindPaths(m, n, N - 1, i, j - 1)) % MAX_RANGE;
        }

        table[i][j][N - 1] = result;
        return result;
    }

    int getOnePath(int m, int n, int i, int j) {
        int path = 0;
        if (i == m - 1) {
            path++;
        }
        if (i == 0) {
            path++;
        }
        if (j == n - 1) {
            path++;
        }
        if (j == 0) {
            path++;
        }
        return path;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        getline(cin, line);
        int N = stringToInteger(line);
        getline(cin, line);
        int i = stringToInteger(line);
        getline(cin, line);
        int j = stringToInteger(line);

        int ret = Solution().findPaths(m, n, N, i, j);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
