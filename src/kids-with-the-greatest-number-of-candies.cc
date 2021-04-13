#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res(candies.size(), false);

        int max = 0;
        for (auto &candy: candies) {
            max = std::max(candy, max);
        }

        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= max) {
                res[i] = true;
            }
        }

        return res;
    }
};

int main() {
    vector<pair<vector<int>, int>> testCases {
        {{2,3,5,1,3}, 3},
        {{4,2,1,1,2}, 1},
        {{12,1,12}, 10}
    };

    for (auto &testCase: testCases) {
        for (bool i: Solution().kidsWithCandies(testCase.first, testCase.second)) {
            cout << boolalpha << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
