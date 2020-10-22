#include <vector>
#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        if (points[0] == points[1] || points[0] == points[2] || points[1] == points[2]) {
            return false;
        }
        return std::fabs(getK(points[0], points[1]) - getK(points[0], points[2])) > 1e-5;
    }

    double getK(vector<int> &p1, vector<int> &p2) {
        if (p1[0] == p2[0]) {
            return std::numeric_limits<double>::max();
        }
        return ((double)p1[1] - p2[1]) / (p1[0] - p2[0]);
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{1,1},{2,3},{3,2}},
        {{1,1},{2,2},{3,3}},
        {{0,1},{1,1},{2,2}}
    };
    for (auto &testCase: testCases) {
        cout << boolalpha << Solution().isBoomerang(testCase) << endl;
    }
    return 0;
}
