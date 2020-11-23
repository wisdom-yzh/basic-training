#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    static constexpr double EPS = 1e-6;

    bool checkStraightLine(vector<vector<int>>& coordinates) {
        std::sort(coordinates.begin(), coordinates.end(), [] (vector<int> &a, vector<int> &b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });

        bool init = false;
        bool K = false;
        double gradient = 0.0;

        for (int i = 0; i < coordinates.size() - 1; i++) {
            const auto &a = coordinates[i];
            const auto &b = coordinates[i + 1];

            if (!init) {
                init = true;
                if (a[0] == b[0]) {
                    K = true;
                } else {
                    K = false;
                    gradient = (a[1] - b[1]) / static_cast<double>(a[0] - b[0]);
                }
            } else {
                if (a[0] == b[0])  {
                    if (!K) return false;
                    continue;
                }

                if (std::fabs((a[1] - b[1]) / static_cast<double>(a[0] - b[0]) - gradient) > EPS) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{0,0},{0,1},{0,-1}},
        {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}},
        {{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}}
    };
    for (auto &testCase: testCases) {
        cout << boolalpha << Solution().checkStraightLine(testCase) << endl;
    }
    return 0;
}
