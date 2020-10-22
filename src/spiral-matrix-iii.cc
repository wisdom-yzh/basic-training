#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int maxDistance = std::max(std::max(std::max(r0, c0), R - 1 - r0), C - 1 - c0);
        vector<vector<int>> points;

        points.push_back({r0, c0});
        for (int i = 1; i <= maxDistance; i++) {
            int startR = r0 - i;
            int startC = c0 + i;

            for (int j = 0; j < 2 * i; j++) {
                startR++;
                if (startR >= 0 && startR < R && startC >= 0 && startC < C) {
                    points.push_back({startR, startC});
                }
            }
            for (int j = 0; j < 2 * i; j++) {
                startC--;
                if (startR >= 0 && startR < R && startC >= 0 && startC < C) {
                    points.push_back({startR, startC});
                }
            }
            for (int j = 0; j < 2 * i; j++) {
                startR--;
                if (startR >= 0 && startR < R && startC >= 0 && startC < C) {
                    points.push_back({startR, startC});
                }
            }
            for (int j = 0; j < 2 * i; j++) {
                startC++;
                if (startR >= 0 && startR < R && startC >= 0 && startC < C) {
                    points.push_back({startR, startC});
                }
            }
        }

        return points;
    }
};

int main() {
    vector<vector<int>> cases {
        { 1, 4, 0, 0 },
        { 5, 6, 1, 4 }
    };

    for (const auto &c: cases) {
        cout << "R=" << c[0] << ",C=" << c[1] << ",r0=" << c[2] << ",c0=" << c[3] <<  endl;
        for (const auto &item: Solution().spiralMatrixIII(c[0], c[1], c[2], c[3])) {
            cout << "[" << item[0] << "," << item[1] << "]" << endl;
        }
    }

    return 0;
}
