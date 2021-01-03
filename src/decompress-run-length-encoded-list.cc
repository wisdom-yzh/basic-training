#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size() - 1; i += 2) {
            for (int j = 0; j < nums[i]; j++) {
                res.push_back(nums[i + 1]);
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> testCases {
        {1,2,3,4},
        {1,1,2,3}
    };
    for (auto &testCase: testCases) {
        for (auto &x: Solution().decompressRLElist(testCase)) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}
