#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        const int size = nums.size();
        int i = 0, j = 1;

        vector<int> result;

        for (i = 0; i < size; i++) {
            for (j = i + 1; j < size; j++) {
                if (nums[i] + nums[j] == target) {
                    result = { i, j };
                    return result;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 1, 2, 3 };
    vector<int> result = solution.twoSum(nums, 3);
    for (vector<int>::iterator iter = result.begin();
            iter != result.end();
            iter++) {
        cout << *iter;
    }
    return 0;
}
