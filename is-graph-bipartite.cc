#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    static constexpr int BLACK = 1;
    static constexpr int WHITE = 2;

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), 0);

        for (int i = 0; i < graph.size(); i++) {
            if (!check(graph, color, i)) {
                return false;
            }
        }

        return true;
    }

    bool check(vector<vector<int>> &graph, vector<int> &color, int vertex) {
        if (color[vertex] != 0) {
            return true;
        }

        color[vertex] = BLACK;
        queue<int> q;
        q.push(vertex);

        while (!q.empty()) {
            auto &v = q.front();

            for (const auto &neighbour: graph[v]) {
                if (color[neighbour] == color[v]) {
                    return false;
                }
                if (color[neighbour] == 0) {
                    color[neighbour] = color[v] == BLACK ? WHITE : BLACK;
                    q.push(neighbour);
                }
            }

            q.pop();
        }

        return true;
    }
};

int main() {
    return 0;
}
