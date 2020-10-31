#include <vector>
#include <queue>
#include <iostream>
#include <tuple>
using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<vector<bool>>> g(n, vector<vector<bool>>(n, {false, false}));

        for (auto &e: red_edges) {
            g[e[0]][e[1]][0] = true;
        }
        for (auto &e: blue_edges) {
            g[e[0]][e[1]][1] = true;
        }

        vector<vector<int>> result(3, vector<int>(n, -1));
        vector<vector<bool>> used(2, vector<bool>(n, false));

        result[0][0] = result[1][0] = 0;

        while (true) {
            int v = -1, color = 0, minDist = -1;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j <= 1; j++) {
                    if (result[j][i] != -1 &&
                        (minDist == -1 || result[j][i] < minDist) &&
                        !used[j][i]) {
                        minDist = result[j][i];
                        color = j;
                        v = i;
                    }
                }
            }

            if (minDist == -1) {
                break;
            }

            used[color][v] = true;
            for (int i = 1; i < n; i++) {
                for (int u = 0; u < n; u++) {
                    if (!used[1 - color][u] && g[v][u][1 - color] &&
                        (result[1 - color][u] == -1 || result[1 - color][u] > result[color][v] + 1)) {
                        result[1 - color][u] = result[color][v] + 1;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (result[0][i] == -1) {
                result[2][i] = result[1][i];
            } else if (result[1][i] == -1) {
                result[2][i] = result[0][i];
            } else {
                result[2][i] = std::min(result[0][i], result[1][i]);
            }
        }
        return result[2];
    }
};

int main() {
    vector<tuple<int, vector<vector<int>>, vector<vector<int>>>> testCases {
        { 3, {{0,1}, {1,2}}, {} },
        { 3, {{0,1}}, {{2,1}} },
        { 3, {{1,0}}, {{2,1}} },
        { 3, {{0,1}}, {{1,2}} },
        { 3, {{0,1}, {0,2}}, {{1,0}} },
        { 5, {{0,1},{1,2},{2,3},{3,4}}, {{1,2},{2,3},{3,1}} }
    };
    for (auto &testCase: testCases) {
        for (auto &val: Solution().shortestAlternatingPaths(get<0>(testCase), get<1>(testCase), get<2>(testCase))) {
            cout << val << ' ';
        }
        cout << endl;
    }
    return 0;
}
