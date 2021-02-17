#include <vector>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = 30 * hour + minutes / 2.0;
        if (h > 360) {
            h -= 360;
        }
        double m = 6 * minutes;
        double angle = std::fabs(h - m);

        return std::min(angle, 360 - angle);
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int hour = stringToInteger(line);
        getline(cin, line);
        int minutes = stringToInteger(line);

        double ret = Solution().angleClock(hour, minutes);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
