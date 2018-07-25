#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool checkDuplicate (vector<vector<int>> &collection, vector<int> &newArr) {
        for (auto i = collection.begin(); i != collection.end(); i++) {
            auto arr = *i;
            if (arr[0] == newArr[0] &&
                arr[1] == newArr[1] &&
                arr[2] == newArr[2]) {
                return true;
            }
        }

        return false;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) {
            return result;
        }

        sort(nums.begin(), nums.end());

        for (auto i = nums.begin(); i != nums.end() - 3; i++) {
            for (auto j = i + 1; j != nums.end() - 2; j++) {
                auto p = j + 1, q = nums.end() - 1;
                while (p < q) {
                    const int sum = *i + *j + *p + *q;
                    if (sum < target) {
                        p++;
                        continue;
                    }
                    if (sum > target) {
                        q--;
                        continue;
                    }
                    vector<int> newArr { *i, *j, *p, *q };
                    if (!this->checkDuplicate(result, newArr)) {
                        result.push_back(newArr);
                    }
                    p++;
                    q--;
                }
            }
        }

        return result;
    }
};

int main () {
    Solution s;
    vector<vector<int>> testCases {
        { 1, 0, -1, 0, -2, 2 },
        { 5, 7, 1, 4, 2, -2, -6 },
        { -3, -2, -1, 0, 0, 1, 2, 3 }
    };
    vector<int> targets { 0, 3, 0 };

    auto i = targets.begin();
    auto j = testCases.begin();
    for (; i != targets.end(); i++, j++) {
        auto result = s.fourSum(*j, *i);
        cout << '[' << endl;
        for (auto m = result.begin(); m != result.end(); m++) {
            cout << ' ';
            copy((*m).begin(), (*m).end(), ostream_iterator<int>(cout, ","));
            cout << endl;
        }
        cout << ']' << endl;
    }

    return 0;
}
