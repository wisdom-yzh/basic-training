#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include <iostream>
#include <tuple>
using namespace std;

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int res = -1;
        int nDist = std::numeric_limits<int>::max();
        for (int i = 0; i < points.size(); i++) {
            int px = points[i][0], py = points[i][1];
            if (px == x || py == y) {
                int dist = std::abs(px - x) + std::abs(py - y);
                if (dist < nDist) {
                    nDist = dist;
                    res = i;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<tuple<int, int, vector<vector<int>>>> testCases {
        { 3, 4, {{1,2},{3,1},{2,4},{2,3},{4,4}} },
        { 3, 4, {{3,4}} },
        { 3, 4, {{2,3}} },
    };
    for (auto &[x, y, points]: testCases) {
        cout << Solution().nearestValidPoint(x, y, points) << endl;
    }
    return 0;
}
