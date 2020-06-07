#include <vector>
#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int N = quiet.size();
        vector<vector<int>> rich(N, vector<int>{});

        for (const auto &r: richer) {
            rich[r[1]].push_back(r[0]);
        }

        vector<int> result(N, -1);
        for (int i = 0; i < N; i++) {
            dfs(rich, quiet, result, i);
        };
        return result;
    }

    void dfs(vector<vector<int>> &rich, vector<int> &quiet, vector<int> &result, int i) {
        if (result[i] != -1) {
            return;
        }

        if (rich[i].empty()) {
            result[i] = i;
            return;
        }

        result[i] = i;
        for (const auto &idx: rich[i]) {
            dfs(rich, quiet, result, idx);
            if (quiet[result[idx]] < quiet[result[i]]) {
                result[i] = result[idx];
            }
        }
    }
};

int main() {
    vector<vector<int>> richer { {1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3} };
    vector<int> quiet {3,2,5,4,6,1,7,0};
    for (const auto &elem: Solution().loudAndRich(richer, quiet)) {
        cout << elem << ' ';
    }
    return 0;
}
