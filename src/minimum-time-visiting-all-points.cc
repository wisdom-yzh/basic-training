#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size() - 1; i++) {
            res += std::max(
                std::abs(points[i][0] - points[i + 1][0]),
                std::abs(points[i][1] - points[i + 1][1])
            );
        }
        return res;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        { {1,1},{3,4},{-1,0} },
        { {3,2},{-2,2} }
    };
    for (auto &testCase: testCases) {
        cout << Solution().minTimeToVisitAllPoints(testCase) << endl;
    }
    return 0;
}
