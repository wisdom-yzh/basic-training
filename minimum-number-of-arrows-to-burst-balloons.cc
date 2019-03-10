#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.empty()) {
            return 0;
        }

        int count = 0;
        int arrow = -1;

        std::sort(points.begin(), points.end(), [](pair<int, int> &p1, pair<int, int> &p2) {
            return p1.second == p2.second
                ? p1.first < p2.first
                : p1.second < p2.second;
        });

        for (auto & point: points) {
            if (arrow != -1 && arrow >= point.first) {
                continue;
            }

            arrow = point.second;
            count++;
        }

        return count;
    }
};

int main() {
    vector<pair<int, int>> points {
        {10,16}, {2,8}, {1,6}, {7,12}
    };
    cout << Solution().findMinArrowShots(points);
    return 0;
}
