#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> result;
        auto pMaxElement = std::max_element(nums.begin(), nums.end());
        int MAX = *pMaxElement;
        int count[MAX + 1];
        std::fill(count, count + MAX + 1, 0);

        for (const auto &num: nums) {
            count[num]++;
        }
        for (int i = MAX - 1; i >= 0; i--) {
            count[i] += count[i + 1];
        }
        for (const auto &num: nums) {
            if (count[num] == 1) {
                result.push_back("Gold Medal");
            } else if (count[num] == 2) {
                result.push_back("Silver Medal");
            } else if (count[num] == 3) {
                result.push_back("Bronze Medal");
            } else {
                result.push_back(std::to_string(count[num]));
            }
        }

        return result;
    }
};

int main() {
    vector<int> nums { 5, 4, 3, 2, 1 };
    auto result = Solution().findRelativeRanks(nums);
    for (const auto &rank: result) {
        cout << rank << ',';
    }

    vector<int> nums2 { 10, 3, 8, 9, 4 };
    result = Solution().findRelativeRanks(nums2);
    for (const auto &rank: result) {
        cout << rank << ',';
    }
    return 0;
}
