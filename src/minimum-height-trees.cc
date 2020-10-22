#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<vector<bool>> graph(n, vector<bool>(n, false));
        vector<int> degrees(n, 0);

        for (auto &edge: edges) {
            graph[edge.second][edge.first] = graph[edge.first][edge.second] = true;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j]) {
                    degrees[i]++;
                }
            }
        }

        vector<bool> exist(n, true);
        for (;;) {
            vector<int> leaves;
            vector<int> others;
            for (int i = 0; i < n; i++) {
                if (degrees[i] == 1) {
                    leaves.push_back(i);
                } else if (degrees[i] > 1) {
                    others.push_back(i);
                }
            }

            if (others.size() == 0) {
                break;
            }

            for (auto &leaf: leaves) {
                for (int j = 0; j < n; j++) {
                    if (graph[leaf][j]) {
                        graph[leaf][j] = graph[j][leaf] = false;
                        degrees[leaf] = 0;
                        exist[leaf] = false;
                        degrees[j]--;
                    }
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (exist[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};

int main() {
    vector<pair<int, int>> edges = {
      { 1, 0 }, { 1, 2 }, { 1, 3 }
    };
    for (auto &i: Solution().findMinHeightTrees(4, edges)) {
        cout << i << ',';
    }
    cout << endl;

    vector<pair<int, int>> edges2 = {
      { 0, 3 }, { 1, 3 }, { 2, 3 }, { 4, 3 }, { 5, 4 }
    };
    for (auto &i: Solution().findMinHeightTrees(6, edges2)) {
        cout << i << ',';
    }
    cout << endl;
    return 0;
}
