#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int odd = 0, even = 0;
        for (int i = 0; i < nums.size(); i++) {
            int minusValue = 0;
            if (i != 0) {
                minusValue = std::max(minusValue, nums[i] - nums[i - 1] + 1);
            }
            if (i != nums.size() - 1) {
                minusValue = std::max(minusValue, nums[i] - nums[i + 1] + 1);
            }

            if ((i % 2) == 0) {
                odd += minusValue;
            } else {
                even += minusValue;
            }
        }

        return std::min(odd, even);
    }
};

int main() {
    vector<vector<int>> testCases {
        { 1,2,3 },
        { 9,6,1,6,2 }
    };
    for (auto &testCase: testCases) {
        cout << Solution().movesToMakeZigzag(testCase) << endl;
    }
    return 0;
}
