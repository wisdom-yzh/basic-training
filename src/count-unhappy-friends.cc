#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> level(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                level[i][preferences[i][j]] = j;
            }
        }

        vector<int> matches(n, 0);
        for (auto &p: pairs) {
            matches[p[0]] = p[1];
            matches[p[1]] = p[0];
        }

        int res = 0;
        for (int x = 0; x < n; x++) {
            int y = matches[x];
            int lv = level[x][y];
            for (int i = 0; i < lv; i++) {
                int u = preferences[x][i];
                int v = matches[u];
                if (level[u][x] < level[u][v]) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<tuple<int, vector<vector<int>>, vector<vector<int>>>> testCases {
        { 4, {{1,2,3},{3,2,0},{3,1,0},{1,2,0}}, {{0,1},{2,3}} },
        { 2, {{1}, {0}}, {{1, 0}} },
        { 4, {{1, 3, 2}, {2, 3, 0}, {1, 3, 0}, {0, 2, 1}}, {{1, 3}, {0, 2}} },
    };
    for (auto &testCase: testCases) {
        cout << Solution().unhappyFriends(get<0>(testCase), get<1>(testCase), get<2>(testCase))
             << endl;
    }
    return 0;
}
