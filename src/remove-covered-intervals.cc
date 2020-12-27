#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [] (vector<int> &a, vector<int> &b) {
            if (a[0] == b[0])  {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        int left = -1, right = -1;
        for (auto iter = intervals.begin(); iter != intervals.end(); ) {
            auto &region = *iter;

            if (left == -1 || right == -1) {
                left = region[0];
                right = region[1];
                iter++;
            } else if (region[1] <= right) {
                iter = intervals.erase(iter);
            } else {
                left = region[0];
                right = region[1];
                iter++;
            }
        }

        return intervals.size();
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{1,4},{3,6},{2,8}},
        {{1,4},{2,3}},
        {{0,10},{5,12}},
        {{3,10},{4,10},{5,11}},
        {{1,2},{1,4},{3,4}}
    };

    for (auto &testCase: testCases) {
        cout << Solution().removeCoveredIntervals(testCase) << endl;
    }
    return 0;
}
