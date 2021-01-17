#include <iostream>
#include <string>
#include <regex>
#include <ctime>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        std::regex re("(.+?)-(.+?)-(.+?)");
        std::smatch match1, match2;
        std::regex_match(date1, match1, re);
        std::regex_match(date2, match2, re);

        std::tm tm1, tm2;
        std::memset(&tm1, 0, sizeof(tm1)),
        std::memset(&tm2, 0, sizeof(tm2)),
        tm1.tm_year = std::stoi(match1[1]) - 1900;
        tm1.tm_mon = std::stoi(match1[2]) - 1;
        tm1.tm_mday = std::stoi(match1[3]);
        tm2.tm_year = std::stoi(match2[1]) - 1900;
        tm2.tm_mon = std::stoi(match2[2]) - 1;
        tm2.tm_mday = std::stoi(match2[3]);

        double res = std::difftime(std::mktime(&tm1), std::mktime(&tm2)) / 86400.0;
        return std::abs(res);
    }
};

int main() {
    vector<pair<string, string>> testCases {
        { "2019-06-29", "2019-06-30" },
        { "2020-01-15", "2019-12-31" },
        { "1971-06-29", "2010-09-23" }
    };

    for (auto &testCase: testCases) {
        cout << Solution().daysBetweenDates(testCase.first, testCase.second) << endl;
    }
    return 0;
}
