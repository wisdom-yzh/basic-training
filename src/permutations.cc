#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void recurstionPermute(vector<int> &nums, vector<bool> &numUsed,
            vector<vector<int>> &result, vector<int> &current) {
        vector<bool> allUsed(nums.size(), true);
        if (allUsed == numUsed) {
            result.push_back(current);
            return;
        }

        for (unsigned int i = 0; i < nums.size(); i++) {
            if (numUsed[i]) {
                continue;
            }
            numUsed[i] = true;
            current.push_back(nums[i]);
            this->recurstionPermute(nums, numUsed, result, current);
            current.pop_back();
            numUsed[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> numUsed(nums.size(), false);
        vector<int> current;
        this->recurstionPermute(nums, numUsed, result, current);
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums { 1 };
    for (auto row: s.permute(nums)) {
        for (auto num: row) {
            cout << num << ',';
        }
        cout << endl;
    }
    return 0;
}
