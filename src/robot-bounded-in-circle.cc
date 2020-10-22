#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    const static vector<char> DIRECTION;

    bool isRobotBounded(string instructions) {
        int d = 0, x = 0, y = 0;

        for (const auto &ch: instructions) {
            if (ch == 'G') {
                switch (DIRECTION[d]) {
                    case 'N': y--; break;
                    case 'E': x++; break;
                    case 'S': y++; break;
                    case 'W': x--; break;
                }
            } else if (ch == 'L') {
                d = (d - 1) % DIRECTION.size();
            } else {
                d = (d + 1) % DIRECTION.size();
            }
        }

        return (x == 0 && y == 0) || d != 0;
    }
};

const vector<char> Solution::DIRECTION = { 'N', 'E', 'S', 'W' };

int main() {
    vector<string> testCases {
        "GGLLGG",
        "GG",
        "GL",
    };
    for (auto &testCase: testCases) {
        cout << boolalpha << Solution().isRobotBounded(testCase) << endl;
    }
    return 0;
}
