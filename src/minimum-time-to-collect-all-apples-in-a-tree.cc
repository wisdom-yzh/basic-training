#include <vector>
#include <tuple>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> mat(n, vector<int>({}));
        for (auto &edge: edges) {
            mat[edge[0]].push_back(edge[1]);
            mat[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        return minTimeRecursion(0, mat, hasApple, visited);
    }

    int minTimeRecursion(int v0, vector<vector<int>>& mat, vector<bool>& hasApple, vector<bool>& visited) {
        visited[v0] = true;
        int res = 0;
        for (auto &v1: mat[v0]) {
            if (visited[v1]) {
                continue;
            }
            int branch = minTimeRecursion(v1, mat, hasApple, visited);
            if (branch == 1) {
                res += 2;
            } else if (branch != 0) {
                res += (branch + 2);
            }
        }
        if (v0 != 0 && res == 0 && hasApple[v0]) {
            return 1;
        }
        return res;
    }
};

int main() {
    vector<tuple<int, vector<vector<int>>, vector<bool>>> testCases {
        { 7, {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}}, {false,false,true,false,true,true,false} },
        { 7, {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}}, {false,false,true,false,false,true,false} },
        { 7, {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}}, {false,false,false,false,false,false,false} },
        { 4, {{0,2},{0,3},{1,2}}, {false,true,false,false} }
    };
    for (auto &testCase: testCases) {
        cout << Solution().minTime(get<0>(testCase), get<1>(testCase), get<2>(testCase)) << endl;
    }
    return 0;
}
