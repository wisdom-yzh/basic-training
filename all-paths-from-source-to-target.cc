#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;

        queue<pair<int, vector<int>>> q;
        q.push(make_pair(0, vector<int> { 0 }));

        while (!q.empty()) {
            auto &top = q.front();
            int index = top.first;
            vector<int> &path = top.second;

            for (auto &nextIndex: graph[index]) {
                if (std::find(path.begin(), path.end(), nextIndex) != path.end()) {
                    continue;
                }
                vector<int> nextPath(path);
                nextPath.push_back(nextIndex);

                if (nextIndex == graph.size() - 1) {
                    result.push_back(nextPath);
                } else {
                    q.push(make_pair(nextIndex, nextPath));
                }
            }

            q.pop();
        }

        return result;
    }
};

int main() {
    vector<vector<int>> graph {
        {1,2}, {3}, {3}, {}
    };
    Solution().allPathsSourceTarget(graph);
    return 0;
}
