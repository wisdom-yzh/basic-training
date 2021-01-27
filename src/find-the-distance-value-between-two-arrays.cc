#include <vector>
#include <iostream>
#include <tuple>
#include <cmath>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;
        for (int i = 0; i < arr1.size(); i++) {
            bool matched = true;
            for (int j = 0; j < arr2.size(); j++) {
                if (std::abs(arr1[i] - arr2[j]) <= d) {
                    matched = false;
                    break;
                }
            }
            if (matched) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    vector<tuple<vector<int>, vector<int>, int>> testCases {
        {{4,5,8}, {10,9,1,8}, 2}
    };
    for (auto &testCase: testCases) {
        cout << Solution().findTheDistanceValue(get<0>(testCase),
                get<1>(testCase), get<2>(testCase)) << endl;
    }
    return 0;
}
