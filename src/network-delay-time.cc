#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <iostream>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for (int i = 0; i < N; i++) {
            graph[i][i] = 0;
        }
        for (const auto &t: times) {
            graph[t[0] - 1][t[1] - 1] = t[2];
        }

        vector<int> dist = this->dijkstra(graph, K - 1);
        for (const auto &d: dist) {
            if (d == -1) {
                return -1;
            }
        }
        return *std::max_element(dist.begin(), dist.end());
    }

    vector<int> dijkstra(vector<vector<int>> &graph, int K) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int> dist(graph.size(), -1);

        q.push(make_pair(0, K));
        dist[K] = 0;

        while (!q.empty()) {
            int topDist, topIndex;
            std::tie(topDist, topIndex) = q.top();
            q.pop();

            const auto v = graph[topIndex];
            for (int i = 0; i < v.size(); i++) {
                if (i == topIndex || v[i] == -1) {
                    continue;
                }
                if (dist[i] == -1 || dist[i] > v[i] + topDist) {
                    dist[i] = v[i] + topDist;
                    q.push(make_pair(dist[i], i));
                }
            }
        }

        return dist;
    }
};

int main() {
    vector<vector<int>> times {
        { 2,1,1 },
        { 2,3,1 },
        { 3,4,1 }
    };
    cout << Solution().networkDelayTime(times, 4, 2);
    return 0;
}
