#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        std::sort(costs.begin(), costs.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] - b[0] < a[1] - b[1];
        });

        const int T = costs.size() / 2;
        int res = 0;
        for (int i = 0; i < T; i++) {
            res += costs[i][0] + costs[i + T][1];
        }
        return res;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{10,20},{30,200},{400,50},{30,20}},
        {{259,770},{448,54},{926,667},{184,139},{840,118},{577,469}},
        {{515,563},{451,713},{537,709},{343,819},{855,779},{457,60},{650,359},{631,42}},
    };
    for (auto &testCase: testCases) {
        cout << Solution().twoCitySchedCost(testCase) << endl;
    }
    return 0;
}
