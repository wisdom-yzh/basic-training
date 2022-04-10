#include <algorithm>
#include <array>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    constexpr static int BEGIN = 1950;
    constexpr static int LEN = 101;

    int maximumPopulation(vector<vector<int>>& logs) {
        std::array<int, LEN> arr;
        std::fill(arr.begin(), arr.end(), 0);

        for (auto &log: logs) {
            arr[log[0] - BEGIN]++;
            arr[log[1] - BEGIN]--;
        }

        int res = arr[0], year = BEGIN;
        for (int i = 1; i < LEN; i++) {
            arr[i] += arr[i - 1];
            if (arr[i] > res) {
                res = arr[i];
                year = BEGIN + i;
            }
        }
        return year;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{1993,1999},{2000,2010}},
        {{1950,1961},{1960,1971},{1970,1981}}
    };
    for (auto &testCase: testCases) {
        cout << Solution().maximumPopulation(testCase) << endl;
    }
    return 0;
}
