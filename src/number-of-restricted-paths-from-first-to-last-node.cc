#include <limits>
#include <vector>
#include <tuple>
#include <iostream>
#include <queue>
#include <cstdint>
#include <algorithm>
using namespace std;

class Solution {
public:
    constexpr static int MOD = 1e9 + 7;

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<int> dis(n + 1, std::numeric_limits<int>::max());
        vector<vector<pair<int,int>>> g(n + 1);
        for (auto &e: edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }

        priority_queue<pair<int,int>> pq;
        pq.push({0, n});
        dis[n] = 0;

        while (!pq.empty()) {
            auto [d,x] = pq.top();
            pq.pop();
            d = -d;
            if (d != dis[x]) {
                continue;
            }
            for (auto [y, w]: g[x]) {
                if (dis[y] > d + w) {
                    dis[y] = d + w;
                    pq.push({ -dis[y], y });
                }
            }
        }

        vector<int> a(n), dp(n + 1);
        for (int i = 1; i <= n; i++) {
            a[i - 1] = i;
        }
        sort(a.begin(), a.end(), [&](auto x, auto y) {
            return dis[x] > dis[y];
        });

        dp[1] = 1;
        for (auto &x : a) {
            for (auto &[y, w]: g[x]) {
                if (dis[y] < dis[x]) {
                    dp[y] = (dp[y] + dp[x]) % MOD;
                }
            }
        }
        return dp[n];
    }
};

int main() {
    vector<tuple<int, vector<vector<int>>>> testCases {
        { 5, {{1,2,3},{1,3,3},{2,3,1},{1,4,2},{5,2,2},{3,5,1},{5,4,10}} },
        { 7, {{1,3,1},{4,1,2},{7,3,4},{2,5,3},{5,6,1},{6,7,2},{7,5,3},{2,6,4}} }
    };
    for (auto &[n, edges]: testCases) {
        cout << Solution().countRestrictedPaths(n, edges) << endl;
    }
    return 0;
}
