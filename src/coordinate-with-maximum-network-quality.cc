#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        double maxValue = 0;
        vector<int> res {0, 0};

        for (int x = 0; x <= 51; x++) {
            for (int y = 0; y <= 51; y++) {
                double cur = 0;
                for (auto &t: towers) {
                    int xi = t[0], yi = t[1], qi = t[2];
                    double d = std::sqrt((x - xi) * (x - xi) + (y - yi) * (y - yi));
                    if (d <= (double)radius) {
                        cur += floor((double)qi / (1 + d));
                    }
                }

                if (cur > maxValue) {
                    maxValue= cur;
                    res = {x, y};
                }
            }
        }
        return res;
    }
};

int main() {
    vector<pair<vector<vector<int>>, int>> testCases {
        {{{1,2,5},{2,1,7},{3,1,9}}, 2},
        {{{23,11,21}}, 9},
        {{{1,2,13},{2,1,7},{0,1,9}}, 2},
        {{{2,1,9},{0,1,9}}, 2}
    };
    for (auto &[towers, radius]: testCases) {
        for (auto &x: Solution().bestCoordinate(towers, radius)) {
            cout << x << ',';
        }
        cout << endl;
    }
    return 0;
}
