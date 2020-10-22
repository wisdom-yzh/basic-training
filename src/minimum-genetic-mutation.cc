#include <vector>
#include <string>
#include <queue>
#include <limits>
#include <iostream>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int endIndex = -1;
        std::vector<std::string> gene;
        gene.push_back(std::move(start));
        for (int i = 0; i < bank.size(); i++) {
            if (bank[i] == end) {
                endIndex = i + 1;
            }
            gene.push_back(std::move(bank[i]));
        }

        if (endIndex == -1) {
            return -1;
        }

        vector<vector<int>> graph(gene.size(), vector<int>(gene.size(), 0));
        for (int i = 0; i < gene.size(); i++) {
            for (int j = i; j < gene.size(); j++) {
                if (i == j) {
                    graph[i][j] = graph[j][i] = 0;
                } else {
                    graph[i][j] = graph[j][i] = mutation(gene[i], gene[j]);
                }
            }
        }

        return dijkstra(graph)[endIndex] == std::numeric_limits<int>::max()
            ? -1
            : dijkstra(graph)[endIndex];
    }

    int mutation(string &a, string &b) {
        int changed = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                changed++;
            }
            if (changed > 1) {
                break;
            }
        }
        return changed == 1 ? 1 : -1;
    }

    vector<int> dijkstra(vector<vector<int>> &g) {
        vector<bool> visited(g.size(), false);

        vector<int> result(g.size());
        for (int i = 0; i < g.size(); i++) {
            result[i] = g[0][i] != -1 ? g[0][i] : std::numeric_limits<int>::max();
        }

        int current = 0, next = 0;
        do {
            current = next;

            for (int i = 1; i < g.size(); i++) {
                if (i == current) {
                    continue;
                }
                if (g[current][i] != -1) {
                    result[i] = std::min(result[i], g[current][i] + result[current]);
                }
            }

            visited[current] = true;

            next = -1;
            int minValue = std::numeric_limits<int>::max();
            for (int i = 1; i < visited.size(); i++) {
                if (!visited[i] && minValue > result[i]) {
                   next = i;
                   minValue = result[i];
                }
            }
        } while (next != -1);

        return result;
    }
};

int main() {
    vector<string> bank { "AACCGGTA" };
    std::cout << Solution().minMutation("AACCGGTT", "AACCGGTA", bank);
    return 0;
}
