#include <vector>
#include <tuple>
#include <iostream>
using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start > destination) {
            std::swap(start, destination);
        }

        int clockwise = 0, counterclockwise = 0;
        for (int i = start; i < destination; i++) {
            clockwise += distance[i];
        }
        for (int i = start; i != destination; ) {
            if (i == 0) {
                i = distance.size() - 1;
            } else {
                i--;
            }
            counterclockwise += distance[i];
        }

        return std::min(clockwise, counterclockwise);
    }
};

int main() {
    vector<tuple<vector<int>, int, int>> testCases {
        { { 1, 2, 3, 4 }, 0, 1 },
        { { 1, 2, 3, 4 }, 0, 2 },
        { { 1, 2, 3, 4 }, 0, 3 },
    };
    for (auto &testCase: testCases) {
        cout << Solution().distanceBetweenBusStops(
            get<0>(testCase),
            get<1>(testCase),
            get<2>(testCase)
        ) << endl;
    }
    return 0;
}
