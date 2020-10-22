#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        std::map<int, int> sumToIndex {
            std::make_pair(0, -1)
        };

        int sum = 0, max = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 0 ? -1 : 1;

            auto p = sumToIndex.find(sum);
            if (p == sumToIndex.end()) {
                sumToIndex.emplace(sum, i);
            } else {
                max = std::max(max, i - p->second);
            }
        }

        return max;
    }
};

int main() {
    vector<int> nums { 0, 1, 1, 0, 0, 1, 1, 1, 0 };
    std::cout << Solution().findMaxLength(nums);
    return 0;
}
