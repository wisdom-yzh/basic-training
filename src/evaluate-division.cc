#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    using Graph = map<string, map<string, double>>;

    vector<double> calcEquation(
        vector<pair<string, string>> equations,
        vector<double>& values,
        vector<pair<string, string>> queries
    ) {
        Graph g;
        for (size_t i = 0; i < values.size(); i++) {
            if (g.find(equations[i].first) == g.end()) {
                g.emplace(
                    equations[i].first,
                    map<string, double> { make_pair(equations[i].second, values[i]) }
                );
            } else {
                g[equations[i].first].emplace(make_pair(
                    equations[i].second,
                    values[i]
                ));
            }

            if (g.find(equations[i].second) == g.end()) {
                g.emplace(
                    equations[i].second,
                    map<string, double> { make_pair(equations[i].first, 1.0 / values[i]) }
                );
            } else {
                g[equations[i].second].emplace(make_pair(
                    equations[i].first,
                    1.0 / values[i]
                ));
            }
        }

        vector<double> result;
        Graph cached;
        for (const auto &query: queries) {
            result.push_back(calcEquation(g, query, cached));
        }
        return result;
    }

    double calcEquation(Graph &g, const pair<string, string> &query, Graph &cached) {
        string first(query.first);
        string second(query.second);

        if (cached[first][second]) {
            return cached[first][second];
        }
        
        if (first == second) {
            return g.find(first) == g.end() ? -1.0 : 1.0;
        }

        if (g.find(first) == g.end() ||
            g.find(second) == g.end()) {
            return -1.0;
        }

        return bfs(g, first, second, cached);
    }

    double bfs(Graph &g, string &first, string &second, Graph &cached) {
        if (cached.find(first) == cached.end()) {
            cached.emplace(first, map<string, double> { make_pair(first, 1.0) });
        }

        set<string> visited;
        visited.emplace(first);
        queue<pair<string, double>> q;
        q.push(make_pair(first, 1.0));

        while (!q.empty()) {
            auto & node = q.front();
            auto & nextNodes = g[node.first];

            for (auto &nextNode: nextNodes) {
                if (visited.find(nextNode.first) != visited.end()) {
                    continue;
                }
                auto next = make_pair(nextNode.first, node.second * nextNode.second);
                cached[first].emplace(next.first, next.second);
                q.push(next);

                if (next.first == second) {
                    return next.second;
                }
            }

            q.pop();
        }

        return -1.0;
    }
};

int main() {
    Solution s;
    vector<pair<string, string>> equations;
    vector<double> values { 2.0, 3.0 };
    vector<pair<string, string>> queries {
        { "a", "c" },
        { "b", "a" },
        { "a", "e" },
        { "a", "a" },
        { "x", "x" }
    };
    auto results = s.calcEquation({{ "a", "b" }, { "b", "c" }}, values, queries);
    for (auto & result: results) {
        cout << result << endl;
    }
    return 0;
}
