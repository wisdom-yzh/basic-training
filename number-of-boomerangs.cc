#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int result = 0;
        int size = points.size();
        std::map<int, int> table;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == j) {
                    continue;
                }

                int dist = distance(points[i], points[j]);
                if (table.find(dist) == table.end()) {
                    table[dist] = 1;
                } else {
                    table[dist]++;
                }
            }

            for (auto &item: table) {
                result += item.second * (item.second - 1);
            }
            table.clear();
        }

        return result;
    }

    int distance(pair<int, int> &a, pair<int, int> &b) {
        int dx = a.first - b.first;
        int dy = a.second - b.second;
        return dx * dx + dy * dy;
    }
};

int main() {
    vector<pair<int, int>> points {
        { 0, 0 },
        { 1, 0 },
        { 2, 0 }
    };
    std::cout << Solution().numberOfBoomerangs(points);
    return 0;
}
