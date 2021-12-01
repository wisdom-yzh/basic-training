#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        uint64_t res = 0;

        for (int i = 0, t = 0; i < customers.size(); i++) {
            t = max(customers[i][0], t);
            t += customers[i][1];
            res += (t - customers[i][0]);
        }

        return static_cast<double>(res) / customers.size();
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{1,2},{2,5},{4,3}},
        {{5,2},{5,4},{10,3},{20,1}},
    };

    for (auto &testCase: testCases) {
        cout << Solution().averageWaitingTime(testCase) << endl;
    }
    return 0;
}
