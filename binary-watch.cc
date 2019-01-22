#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        set<string> result;
        readBinaryWatchRecursion(num, 0, 0, 0, 0, result);
        vector<string> out;
        std::copy(result.begin(), result.end(), std::back_inserter(out));
        return out;
    }

    void readBinaryWatchRecursion(int num, int hours, int hourStart, int minutes, int minuteStart, set<string> &result) {
        if (num == 0) {
            result.emplace(format(hours, minutes));
            return;
        }

        int hoursRemain = 0b1111 - hours;
        int minutesRemain = 0b111111 - minutes;
        for (int i = minuteStart; i < 6; i++) {
            int t = (1 << i);
            if ((minutesRemain & t) != 0 && t + minutes < 60) {
                readBinaryWatchRecursion(num - 1, hours, hourStart, minutes + t, i + 1, result);
            }
        }
        for (int i = hourStart; i < 4; i++) {
            int t = (1 << i);
            if ((hoursRemain & t) != 0 && t + hours < 12) {
                readBinaryWatchRecursion(num - 1, hours + t, i + 1, minutes, minuteStart, result);
            }
        }
    }

    string format(int hours, int minutes) {
        static stringstream ss;
        ss.str("");
        ss << hours << ':';
        if (minutes < 10) {
            ss << '0';
        }
        ss << minutes;
        return ss.str();
    }
};

int main() {
    vector<string> vec(Solution().readBinaryWatch(1));
    for (auto &str: vec) {
        cout << str << endl;
    }
    return 0;
}
