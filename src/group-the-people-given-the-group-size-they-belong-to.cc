#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> result;

        for (int i = 0; i < groupSizes.size(); i++) {
            if (groupSizes[i] == 0) {
                continue;
            }
            vector<int> group { i };
            int remain = groupSizes[i] - 1;
            for (int j = i + 1; remain > 0; j++) {
                if (groupSizes[j] == groupSizes[i]) {
                    remain--;
                    groupSizes[j] = 0;
                    group.push_back(j);
                }
            }
            result.push_back(std::move(group));
        }

        return result;
    }
};

int main() {
    vector<vector<int>> testCases {
        {3,3,3,3,3,1,3},
        {2,1,3,3,3,2}
    };
    for (auto &testCase: testCases) {
        for (auto &row: Solution().groupThePeople(testCase)) {
            for (auto &x: row) {
                cout << x << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
