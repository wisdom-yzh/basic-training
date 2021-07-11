#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<double, int>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            auto& e = edges[i];
            graph[e[0]].emplace_back(succProb[i], e[1]);
            graph[e[1]].emplace_back(succProb[i], e[0]);
        }

        priority_queue<pair<double, int>> q;
        vector<double> prob(n, 0);

        q.emplace(1, start);
        prob[start] = 1;
        while (!q.empty()) {
            auto pr = q.top().first;
            auto node = q.top().second;
            q.pop();
            if (pr < prob[node]) {
                continue;
            }
            for (auto &iter : graph[node]) {
                auto &prNext = iter.first;
                auto &nodeNext = iter.second;
                if (prob[nodeNext] < prob[node] * prNext) {
                    prob[nodeNext] = prob[node] * prNext;
                    q.emplace(prob[nodeNext], nodeNext);
                }
            }
        }
        return prob[end];

    }
};

int main() {
    return 0;
}
