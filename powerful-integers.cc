#include <vector>
#include <tuple>
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> nums;
        int xNum = 1, yNum = 1;

        while (xNum < bound) {
            yNum = 1;
            while (xNum + yNum <= bound) {
                nums.insert(xNum + yNum);
                if (y == 1) {
                    break;
                }
                yNum = yNum == 1 ? y : yNum * y;
            }

            if (x == 1) {
                break;
            }
            xNum = xNum == 1 ? x : xNum * x;
        }

        return vector<int>(nums.begin(), nums.end());
    }
};

int main() {
    vector<tuple<int, int, int>> testCases {
        { 2, 1, 10 },
        { 1, 1, 3 },
        { 2, 3, 10 },
        { 3, 5, 15 }
    };
    for (auto &testCase: testCases) {
        int x, y, bound;
        std::tie(x, y, bound) = testCase;
        for (const auto &num: Solution().powerfulIntegers(x, y, bound)) {
            cout << num << ' ';
        }
        cout << endl;
    }
    return 0;
}
