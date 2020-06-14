#include <vector>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> isSafe(N, -1);
        vector<int> result;

        for (int i = 0; i < N; i++) {
            vector<bool> visited(N, false);
            if (check(graph, isSafe, i, visited) == 1) {
                result.push_back(i);
            }
        }

        return result;
    }

    bool check(vector<vector<int>> &graph, vector<int> &isSafe, int nodeIndex, vector<bool> &visited) {
        if (isSafe[nodeIndex] != -1) {
            return isSafe[nodeIndex];
        }

        if (graph[nodeIndex].empty()) {
            isSafe[nodeIndex] = 1;
            return true;
        }

        if (visited[nodeIndex]) {
            return false;
        }

        visited[nodeIndex] = true;
        for (const auto &nextIndex: graph[nodeIndex]) {
            if (!check(graph, isSafe, nextIndex, visited)) {
                isSafe[nodeIndex] = 0;
                return false;
            }
        }
        visited[nodeIndex] = false;
        isSafe[nodeIndex] = 1;
        return true;
    }
};

int main() {
    vector<vector<int>> graph { {1,2},{2,3},{5},{0},{5},{},{} };
    Solution().eventualSafeNodes(graph);
    return 0;
}
