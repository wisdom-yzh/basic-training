#include <iostream>
#include <sstream>
#include <map>
#include <cmath>
using namespace std;

class Solution {
public:
    int mirrorReflection(int p, int q) {
        std::map<std::pair<int, int>, int> dict {
            { { p, 0 }, 0 },
            { { p, p }, 1 },
            { { 0, p }, 2 },
        };
        int x = p, y = q, dx = -1, dy = 1;
        while (dict.find({ x, y }) == dict.end()) {
            next(x, y, dx, dy, p, q);
        }
        return dict.find({x, y})->second;
    }

    void next(int &x, int &y, int &dx, int &dy, int p, int q) {
        x += dx * p;
        dx = -dx;
        y += dy * q;
        if (y > p) {
            y = p - (y - p);
            dy = -dy;
        } else if (y < 0) {
            y = -y;
            dy = -dy;
        }
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int p = stringToInteger(line);
        getline(cin, line);
        int q = stringToInteger(line);

        int ret = Solution().mirrorReflection(p, q);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
