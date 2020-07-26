#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        std::queue<tuple<int, int, int>> leftRegion;
        int minValue = A[0], maxValue = A[0];

        for (int i = 1; i < A.size(); i++) {
            while (!leftRegion.empty()) {
                if (std::get<2>(leftRegion.front()) > A[i]) {
                    leftRegion.pop();
                } else {
                    break;
                }
            }
            if (A[i] < minValue) {
                minValue = A[i];
            } else if (A[i] >= maxValue) {
                leftRegion.push(make_tuple(i, minValue, maxValue));
                maxValue = A[i];
            }
        }

        return std::get<0>(leftRegion.front());
    }
};

int main() {
    vector<vector<int>> testCases {
        {5,0,3,8,6},
        {1,1,1,0,6,12}
    };
    for (auto &testCase: testCases) {
        cout << Solution().partitionDisjoint(testCase) << endl;
    }
    return 0;
}
