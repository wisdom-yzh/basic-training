#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) {
            return false;
        }

        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if ((sum % 4) != 0) {
            return false;
        }

        std::sort(nums.begin(), nums.end(), std::greater<int>());
        vector<int> edges(4, 0);
        return this->dfs(edges, nums, 0, sum / 4);
    }

private:
    bool dfs(vector<int> &edges, vector<int> &nums, int index, int target) {
        if (index == nums.size()) {
            return edges[0] == edges[1] &&
                edges[1] == edges[2] &&
                edges[2] == edges[3];
        }
        for (auto iter = edges.begin(); iter != edges.end(); iter++) {
            *iter += nums[index];
            if (*iter <= target &&
                dfs(edges, nums, index + 1, target)) {
                return true;
            }
            *iter -= nums[index];
        }
        return false;
    }
};

int main() {
    vector<int> stick1 {1,1,2,2,2};
    std::cout << boolalpha << Solution().makesquare(stick1) << std::endl;
    vector<int> stick2 {3,3,3,3,4};
    std::cout << boolalpha << Solution().makesquare(stick2) << std::endl;
    vector<int> stick3 {1,2,3,4,5,6,7,8,9,10,5,4,3,2,1};
    std::cout << boolalpha << Solution().makesquare(stick3) << std::endl;
    return 0;
}
