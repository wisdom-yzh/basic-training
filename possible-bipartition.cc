#include <vector>
#include <tuple>
#include <iostream>
using namespace std;

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N, vector<int>(N, 0));
        vector<int> group(N, 0);

        for (const auto &relation: dislikes) {
            graph[relation[0] - 1][relation[1] - 1] = graph[relation[1] - 1][relation[0] - 1] = 1;
        }

        for (int i = 0; i < N; i++) {
            if (group[i] != 0) {
                continue;
            }
            group[i] = 1;
            if (!dfs(graph, i, group)) {
                return false;
            }
        }

        return true;
    }

    bool dfs(vector<vector<int>> &graph, int index, vector<int> &group) {
        for (int i = 0; i < graph.size(); i++) {
            if (i == index || !graph[index][i]) {
                continue;
            }
            if (group[index] == group[i]) {
                return false;
            }
            if (group[i] == 0) {
                group[i] = 3 - group[index];
                if (!dfs(graph, i, group)) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<tuple<int, vector<vector<int>>>> cases {
        { 4, { {1, 2}, {1, 3}, {2, 4} } },
        { 3, { {1, 2}, {1, 3}, {2, 3} } },
        { 5, { {1, 2}, {2, 3}, {3, 4}, {4, 5}, {1, 5} } }
    };
    for (const auto &c: cases) {
        vector<vector<int>> dislikes = move(std::get<1>(c));
        cout << boolalpha << Solution().possibleBipartition(get<0>(c), dislikes) << endl;
    }
    return 0;
}
