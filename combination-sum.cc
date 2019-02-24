#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
    void recursionAddNumber(vector<int>& candidates, vector<int>::iterator position,
        int target, vector<int> &current, vector<vector<int>> &result) {
        int value = *position;
        current.push_back(value);
        if (target == value) {
            result.push_back(current);
            return;
        }
        if (target < value) {
            return;
        }

        target -= value;
        for (auto nextPosition = position;
            nextPosition != candidates.end();
            nextPosition++) {
            auto next = current;
            this->recursionAddNumber(candidates, nextPosition, target, next, result);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if (candidates.empty()) {
            return result;
        }

        for (auto position = candidates.begin();
            position != candidates.end();
            position++) {
            vector<int> current;
            this->recursionAddNumber(candidates, position, target,
                    current, result);
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> candidates { 2, 3, 6, 7 };
    int target = 7;

    auto result = s.combinationSum(candidates, target);
    for (auto row: result) {
        copy(row.begin(), row.end(), std::ostream_iterator<int>(cout, ","));
        cout << endl;
    }

    candidates = vector<int> { 2, 3, 5};
    target = 8;

    result = s.combinationSum(candidates, target);
    for (auto row: result) {
        copy(row.begin(), row.end(), std::ostream_iterator<int>(cout, ","));
        cout << endl;
    }

    return 0;
}
