#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> location(1001, 0);

        for (int i = 0; i < trips.size(); i++) {
            for (int j = trips[i][1]; j < trips[i][2]; j++) {
                location[j] += trips[i][0];
                if (location[j] > capacity) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    vector<pair<vector<vector<int>>, int>> testCases {
        { {{2,1,5},{3,3,7}}, 4 },
        { {{2,1,5},{3,3,7}}, 5 },
        { {{2,1,5},{3,5,7}}, 3 },
        { {{3,2,7},{3,7,9},{8,3,9}}, 11 }
    };
    for (auto &testCase: testCases) {
        cout << boolalpha << Solution().carPooling(testCase.first, testCase.second) << endl;
    }
    return 0;
}
