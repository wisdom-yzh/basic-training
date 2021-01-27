#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> res;

        for (int i = 0; i < index.size(); i++) {
            res.insert(next(res.begin(), index[i]), nums[i]);
        }

        return res;
    }
};

int main() {
    vector<pair<vector<int>, vector<int>>> testCases {
        { {0,1,2,3,4}, {0,1,2,2,1} },
        { {1,2,3,4,0}, {0,1,2,3,0} },
        { {1}, {0} },
    };
    for (auto &testCase: testCases) {
        for (auto &x: Solution().createTargetArray(testCase.first, testCase.second)) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}
