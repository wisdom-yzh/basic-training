#include <vector>
#include <tuple>
#include <iostream>
#include <queue>
#include <limits>
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int index = 0, neighbours = std::numeric_limits<int>::max();
        vector<vector<int>> g(n, vector<int>(n, -1));

        for (auto &edge: edges) {
            g[edge[1]][edge[0]] = g[edge[0]][edge[1]] = edge[2];
        }

        for (int i = 0; i < n; i++) {
            int num = this->neighbours(i, n, g, distanceThreshold);
            if (neighbours >= num) {
                index = i;
                neighbours = num;
            }
        }
        return index;
    }

    int neighbours(int i, int n, vector<vector<int>>& g, int distanceThreshold) {
        vector<int> dist(n, std::numeric_limits<int>::max());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        dist[i] = 0;
        q.push({ 0, i });

        while (!q.empty()) {
            int u = q.top().second;
            q.pop();

            for (int v = 0; v < n; v++) {
                if (v == u || g[u][v] == -1) {
                    continue;
                }

                if (dist[v] > dist[u] + g[u][v]) {
                    dist[v] = dist[u] + g[u][v];
                    q.push({ dist[v], v });
                }
            }
        }

        int num = std::accumulate(dist.begin(), dist.end(), 0, [&distanceThreshold](int &acc, int &item) {
            acc += item <= distanceThreshold ? 1 : 0;
            return acc;
        });
        return num - 1;
    }
};

int main() {
    vector<tuple<int, vector<vector<int>>, int>> testCases {
        { 4, {{0,1,3},{1,2,1},{1,3,4},{2,3,1}}, 4 },
        { 5, {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}}, 2 }
    };
    for (auto &testCase: testCases) {
        cout << Solution().findTheCity(get<0>(testCase), get<1>(testCase), get<2>(testCase)) << endl;
    }
    return 0;
}
