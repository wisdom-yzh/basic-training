#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> graph(edges.size(), vector<int>(edges.size(), 0));
        vector<int> degree(edges.size(), 0);

        for (int i = 0; i < graph.size(); i++) {
            graph[i][i] = 1;
        }

        for (const auto &edge: edges) {
            degree[edge[0] - 1]++;
            degree[edge[1] - 1]++;
            graph[edge[0] - 1][edge[1] - 1] = graph[edge[1] - 1][edge[0] - 1] = 1;
        }

        bool findLeaf = false;
        do {
            findLeaf = false;
            for (int i = 0; i < graph.size(); i++) {
                if (degree[i] == 1) {
                    findLeaf = true;
                    for (int j = 0; j < graph.size(); j++) {
                        if (j != i && graph[i][j] == 1) {
                            degree[i]--;
                            degree[j]--;
                            graph[i][j] = graph[j][i] = 0;
                            break;
                        }
                    }
                }
            }
        } while (findLeaf);

        for (auto iter = edges.rbegin(); iter != edges.rend(); iter++) {
            const auto &edge = *iter;
            if (degree[edge[0] - 1] > 1 && degree[edge[1] - 1] > 1) {
                return edge;
            }
        }
        return edges[0];
    }
};

int main() {
    vector<vector<int>> edges { {1,2}, {2,3}, {3,4}, {1,4}, {1,5} };
    for (const auto &el: Solution().findRedundantConnection(edges)) {
        cout << el << ' ';
    }
    return 0;
}
