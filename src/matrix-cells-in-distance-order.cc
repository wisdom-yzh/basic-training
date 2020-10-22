#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> cells;
        cells.push_back({ r0, c0 });
        int maxDist = std::max(
            R - 1 - r0 + C - 1 - c0,
            std::max(
                R - 1 - r0 + c0,
                std::max(r0 + c0, r0 + C - 1 - c0)
            )
        );

        for (int i = 1; i <= maxDist; i++) {
            if (inRange(R, C, { r0 - i, c0 })) cells.push_back({ r0 - i, c0 });
            for (int j = -i + 1; j < i; j++) {
                if (inRange(R, C, { r0 + j, c0 + i - std::abs(j) })) cells.push_back({ r0 + j, c0 + i - std::abs(j) });
                if (inRange(R, C, { r0 + j, c0 - i + std::abs(j) })) cells.push_back({ r0 + j, c0 - i + std::abs(j) });
            }
            if (inRange(R, C, { r0 + i, c0 })) cells.push_back({ r0 + i, c0 });
        }

        return cells;
    }

    bool inRange(int R, int C, vector<int> &&p) {
        return p[0] >= 0 && p[0] < R && p[1] >= 0 && p[1] < C;
    }
};

int main() {
    Solution().allCellsDistOrder(2, 2, 0, 1);
    return 0;
}
