#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> result(n, 0);

        for (auto &booking: bookings) {
            result[booking[0] - 1] += booking[2];
            if (booking[1] < n) {
                result[booking[1]] -= booking[2];
            }
        }

        for (auto iter = next(result.begin()); iter != result.end(); iter++) {
            *iter += *prev(iter);
        }

        return result;
    }
};

int main() {
    vector<pair<vector<vector<int>>, int>> testCases {
        { { {{1,2,10},{2,3,20},{2,5,25}}, 5 } }
    };
    for (auto &testCase: testCases) {
        for (auto &num: Solution().corpFlightBookings(testCase.first, testCase.second)) {
            cout << num << ' ';
        }
        cout << endl;
    }

    return 0;
}
