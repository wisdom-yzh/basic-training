#include <vector>
#include <tuple>
#include <string>
#include <iostream>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> res(n, 0);
        vector<vector<int>> children(n, vector<int>(0));
        vector<set<int>> e(n, set<int>());

        for (auto &edge: edges) {
            e[edge[0]].insert(edge[1]);
            e[edge[1]].insert(edge[0]);
        }

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            auto &u = q.front();

            for (auto &v: e[u]) {
                children[u].push_back(v);
                e[v].erase(u);
                q.push(v);
            }

            q.pop();
        }

        dfs(res, 0, children, labels);

        return res;
    }

    vector<int> dfs(vector<int> &res, int i, vector<vector<int>> &children, string &labels) {
        vector<int> labelCount(26, 0);
        labelCount[labels[i] - 'a']++;

        if (!children[i].empty()) {
            for (auto &j: children[i]) {
                vector<int> subTreeLabelCount = dfs(res, j, children, labels);
                for (int i = 0; i < 26; i++) {
                    labelCount[i] += subTreeLabelCount[i];
                }
            }
        }

        res[i] = labelCount[labels[i] - 'a'];
        return labelCount;
    }
};

int main() {
    vector<tuple<int, vector<vector<int>>, string>> testCases {
        {7, {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}}, "abaedcd"},
        {4, {{0,1},{1,2},{0,3}}, "bbbb"},
        {5, {{0,1},{0,2},{1,3},{0,4}}, "aabab"},
        {6, {{0,1},{0,2},{1,3},{3,4},{4,5}}, "cbabaa"},
        {7, {{0,1},{1,2},{2,3},{3,4},{4,5},{5,6}}, "aaabaaa"},
        {4, {{0,2},{0,3},{1,2}}, "aeed" },
    };
    for (auto &testCase: testCases) {
        for (auto &x: Solution().countSubTrees(get<0>(testCase), get<1>(testCase), get<2>(testCase))) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}
