#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        vector<int> range(nums.size(), 0);

        for (auto &r: requests) {
            range[r[0]]++;
            if (r[1] < nums.size() - 1) {
                range[r[1] + 1]--;
            }
        }

        for (int i = 1; i < nums.size(); i++) {
            range[i] += range[i - 1];
        }

        std::sort(range.begin(), range.end());
        std::sort(nums.begin(), nums.end());

        int idx = nums.size() - 1, res = 0;
        for (int i = range.size() - 1; i >= 0; i--) {
            if (range[i] == 0) {
                break;
            }
            res = (
                static_cast<uint64_t>(res) +
                static_cast<uint64_t>(nums[idx]) * range[i]
            ) % static_cast<uint64_t>(1e9 + 7);
            idx--;
        }

        return res;
    }
};

int main() {
    vector<pair<vector<int>, vector<vector<int>>>> testCases {
        { {1,2,3,4,5}, {{1,3},{0,1}} },
        { {1,2,3,4,5,6}, {{0,1}} },
        { {1,2,3,4,5,10}, {{0,2},{1,3},{1,1}} }
    };

    for (auto &[nums, requests]: testCases) {
        cout << Solution().maxSumRangeQuery(nums, requests) << endl;
    }
    return 0;
}
