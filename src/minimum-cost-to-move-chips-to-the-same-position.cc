#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int x[2] = {0, 0};
        for (auto &num: position) {
            x[num % 2]++;
        }
        return std::min(x[0], x[1]);
    }
};

int main() {
    vector<vector<int>> testCases {
        { 1,2,3 },
        { 2,2,2,3,3 },
        { 1,1000000000 }
    };
    for (auto &testCase: testCases) {
        cout << Solution().minCostToMoveChips(testCase) << endl;
    }
    return 0;
}
