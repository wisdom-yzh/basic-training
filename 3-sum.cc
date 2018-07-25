#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) {
            return result;
        }
        std::sort(nums.begin(), nums.end());
        for (auto i = nums.begin(); i != nums.end(); i++) {
            auto j = i + 1, k = nums.end() - 1;
            while (j < k) {
                int num = *i + *j + *k;
                if (num > 0) {
                    k--;
                } else if (num < 0) {
                    j++;
                } else {
                    vector<int> newVec { *i, *j, *k };
                    if (std::find_if(
                        result.begin(),
                        result.end(),
                        [newVec](vector<int> &vec) {
                            return newVec == vec;
                        }
                    ) == result.end()) {
                        result.push_back(newVec);
                    }
                    if (*j == *k) {
                        break;
                    }
                    k--;
                    j++;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> testCases{
        {},
        { 0 },
        { -1, 0, 1 },
        { -1, 0, 1, 2, -1, -4 },
        { 1, 2, 3, 6, -9, 0 },
        { 2, 4, 5, 7, 8, 10 },
        { -2, 0, 1, 1, 2 }
    };

    for_each(testCases.begin(), testCases.end(), [&s](vector<int> &test) {
        auto result = s.threeSum(test);
        cout << "{\n";
        for_each(result.begin(), result.end(), [](vector<int> &x) {
            cout << "  [" << x[0] << ',' << x[1] << ',' << x[2] << "]\n";
        });
        cout << "}\n";
    });
    return 0;
}
