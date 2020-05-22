#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                for (int k = j + 1; k < points.size(); k++) {
                    maxArea = std::max(maxArea, std::fabs(area(
                        points[i][0], points[i][1],
                        points[j][0], points[j][1],
                        points[k][0], points[k][1]
                    )));
                }
            }
        }
        return maxArea;
    }

    double area(int x1, int y1, int x2, int y2, int x3, int y3) {
        return (x1 * y2 + x3 * y1 + x2 * y3 - x3 * y2 - x1 * y3 - x2 * y1) / 2.0;
    }
};

int main() {
    return 0;
}
