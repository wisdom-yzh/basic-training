#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void recurstionSubset(vector<int> &nums, int index, int count, vector<int> &subResult, vector<vector<int>> &result) {
        if (count == 0) {
            for (auto &oldResult: result) {
                if (oldResult == subResult) {
                    return;
                }
            }
            result.push_back(subResult);
            return;
        }
        for (unsigned int iindex = index + 1; iindex < nums.size(); iindex++) {
            subResult.push_back(nums[iindex]);
            this->recurstionSubset(nums, iindex, count - 1, subResult, result);
            subResult.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        result.push_back({});
        for (unsigned int i = 0; i < nums.size(); i++) {
            for (unsigned int count = 1; count <= nums.size() - i; count++) {
                vector<int> subResult { nums[i] };
                this->recurstionSubset(nums, i, count - 1, subResult, result);
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums { 1, 2, 2 };
    for (auto &vec: Solution().subsetsWithDup(nums)) {
        for (auto &i: vec) {
            cout << i << ',';
        }
        cout << endl;
    }
    return 0;
}
