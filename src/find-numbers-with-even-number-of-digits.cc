#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (auto &num: nums) {
            res += std::to_string(num).size() % 2 == 0 ? 1 : 0;
        }
        return res;
    }
};

int main() {
    vector<vector<int>> testCases {
        { 12,345,2,6,7896 },
        { 555,901,482,1771 }
    };
    for (auto &testCase: testCases) {
        cout << Solution().findNumbers(testCase) << endl;
    }
    return 0;
}
