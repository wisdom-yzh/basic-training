#include <vector>
#include <limits>
#include <iostream>
#include <cmath>
#include <numeric>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> mat(points.size(), vector<int>(points.size(), 0));

        for (int i = 0; i < points.size(); i++) {
            auto &p = points[i];
            int x0 = p[0], y0 = p[1];
            for (int j = 0; j < points.size(); j++) {
                auto &q = points[j];
                int x1 = q[0], y1 = q[1];
                mat[j][i] = mat[i][j] = abs(x1 - x0) + abs(y1 - y0);
            }
        }

        return prim(mat);
    }

    int prim(vector<vector<int>> &g) {
        int res = 0;
        vector<int> lowcost(g.size(), 0);
        vector<bool> s(g.size(), false);

        s[0] = true;
        for (int i = 1; i < g.size(); i++) {
            lowcost[i] = g[0][i];
        }

        for (int i = 0; i < g.size() - 1; i++) {
            int tmp = std::numeric_limits<int>::max(), t = 0;
            for (int j = 0; j < g.size(); j++) {
                if (!s[j] && (lowcost[j] < tmp)) {
                    t = j;
                    tmp = lowcost[j];
                }
            }
            s[t] = true;
            for (int j = 0; j < g.size(); j++) {
                if (!s[j] && (g[t][j] < lowcost[j])) {
                    lowcost[j] = g[t][j];
                }
            }
        }

        return std::accumulate(lowcost.begin(), lowcost.end(), 0);
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{0,0},{2,2},{3,10},{5,2},{7,0}},
        {{3,12},{-2,5},{-4,1}},
        {{0,0},{1,1},{1,0},{-1,1}},
        {{-1000000,-1000000},{1000000,1000000}},
        {{0,0}},
    };
    for (auto &testCase: testCases) {
        cout << Solution().minCostConnectPoints(testCase) << endl;
    }
}
