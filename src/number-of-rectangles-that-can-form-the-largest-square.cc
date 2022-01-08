#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxVal = 0, maxCount = 0;

        for (auto &rect: rectangles) {
            int val = std::min(rect[0], rect[1]);
            if (maxVal == val) {
                maxCount++;
            } else if (maxVal < val) {
                maxCount = 1;
                maxVal = val;
            }
        }

        return maxCount;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{5,8},{3,9},{5,12},{16,5}},
        {{2,3},{3,7},{4,3},{3,7}},
    };
    for (auto &testCase: testCases) {
        cout << Solution().countGoodRectangles(testCase) << endl;
    }
    return 0;
}
