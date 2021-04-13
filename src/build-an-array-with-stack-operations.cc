#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;

        int k = 1;
        for (auto &num: target) {
            while (num > k) {
                k++;
                res.push_back("Push");
                res.push_back("Pop");
            }
            res.push_back("Push");
            k++;
        }

        return res;
    }
};

int main() {
    vector<pair<vector<int>, int>> testCases {
        {{1,3}, 3},
        {{1,2,3},3},
        {{1,2},4},
        {{2,3,4},4}
    };

    for (auto &testCase: testCases) {
        for (const auto &i: Solution().buildArray(testCase.first, testCase.second)) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
