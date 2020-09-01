#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> flowers(N, 0);
        vector<vector<int>> graph(N, vector<int>());
        for (const auto &path: paths) {
            graph[path[0] - 1].push_back(path[1] - 1);
            graph[path[1] - 1].push_back(path[0] - 1);
        }
        for (int i = 0; i < N; i++) {
            const auto &neighbours = graph[i];
            vector<bool> available(4, true);
            for (const auto &n: neighbours) {
                if (flowers[n] != 0) {
                    available[flowers[n] - 1] = false;
                }
            }
            flowers[i] = 1 + std::distance(available.begin(), std::find(available.begin(), available.end(), true));
        }
        return flowers;
    }
};

int main() {
    vector<pair<int, vector<vector<int>>>> testCases {
        { 3, {{1,2},{2,3},{3,1}} },
        { 4, {{1,2},{3,4}} },
        { 4, {{1,2},{2,3},{3,4},{4,1},{1,3},{2,4}} },
        { 10000, {{1,2}} }
    };
    for (auto &testCase: testCases) {
        for (const auto &i: Solution().gardenNoAdj(testCase.first, testCase.second)) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
