#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        const int MAX_NUM = 80000;
        int minIncrement = 0;
        vector<int> dict(MAX_NUM, 0);

        for (const auto &num: A) {
            dict[num]++;
        }
        for (int num = 0; num < dict.size(); num++) {
            int inc = num;
            int count = dict[num];
            while (count > 1) {
                dict[++inc]++;
                minIncrement += inc - num;
                count--;
            }
        }

        return minIncrement;
    }
};

int main() {
    vector<vector<int>> testCases {
        {1,2,2},
        {3,2,1,2,1,7},
    };
    for (auto &testCase: testCases) {
        cout << Solution().minIncrementForUnique(testCase) << endl;
    }
    return 0;
}
