#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](vector<int> &p1, vector<int> &p2) {
            return p1[0] < p2[0];
        });

        int res = 0;
        for (int i = 1; i < points.size(); i++) {
            res = std::max(res, points[i][0] - points[i - 1][0]);
        }

        return res;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{8,7},{9,9},{7,4},{9,7}},
        {{3,1},{9,0},{1,0},{1,4},{5,3},{8,8}}
    };
    for (auto &testCase: testCases) {
        cout << Solution().maxWidthOfVerticalArea(testCase) << endl;
    }
    return 0;
}
