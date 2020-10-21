#include <vector>
#include <iostream>
#include <string>
#include <tuple>
using namespace std;

class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<int> months {0,31,28,31,30,31,30,31,31,30,31,30,31};
        vector<string> dayName {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        int sum = 4;

        for(int i = 1971; i < year; i++) {
            if (((i % 4 ==0) && (i % 100 != 0)) || (i % 400 == 0)) {
                sum += 366;
            } else {
                sum += 365;
            }
        }

        for(int i = 1; i < month; i++) {
            if (i == 2 && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))) {
                sum += 1;
            }
            sum += months[i];
        }
        sum += day;

        return dayName[sum % 7];
    }
};

int main() {
    vector<tuple<int, int, int>> testCases {
        {31, 8, 2019},
        {18, 7, 1999},
        {15, 8, 1993}
    };
    for (auto &test: testCases) {
        cout << Solution().dayOfTheWeek(get<0>(test), get<1>(test), get<2>(test)) << endl;
    }
    return 0;
}
