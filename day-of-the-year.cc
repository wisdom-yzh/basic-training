#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int dayOfYear(string date) {
        vector<std::function<int(int)>> daysOfMonth {
            [](int x) { return 31; },
            [](int x) { return x % 4 == 0 ? 29 : 28; },
            [](int x) { return 31; },
            [](int x) { return 30; },
            [](int x) { return 31; },
            [](int x) { return 30; },
            [](int x) { return 31; },
            [](int x) { return 31; },
            [](int x) { return 30; },
            [](int x) { return 31; },
            [](int x) { return 30; },
            [](int x) { return 31; },
        };

        istringstream iss(date);
        string sYear, sMonth, sDay;
        std::getline(iss, sYear, '-');
        std::getline(iss, sMonth, '-');
        std::getline(iss, sDay, '-');

        int result = 0;
        int year = stoi(sYear), month = stoi(sMonth), day = stoi(sDay);
        for (int i = 0; i < month - 1; i++) {
            result += daysOfMonth[i](year);
        }

        result += day;
        return result;
    }
};

int main() {
    vector<string> testCases {
        "2019-01-09",
        "2019-02-10",
        "2003-03-01",
        "2004-03-01"
    };
    for (auto &date: testCases) {
        cout << Solution().dayOfYear(date) << endl;
    }
    return 0;
}
