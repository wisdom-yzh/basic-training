#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void recursionAddNumber(vector<int>& candidates, vector<int>::iterator position,
        int target, vector<int> &current, vector<vector<int>> &result) {
        int value = *position;
        current.push_back(value);
        if (target == value) {
            sort(current.begin(), current.end());
            for (auto row: result) {
                if (row == current) {
                    return;
                }
            }
            result.push_back(current);
            return;
        }
        if (target < value) {
            return;
        }

        target -= value;
        for (auto nextPosition = position + 1;
            nextPosition != candidates.end();
            nextPosition++) {
            auto next = current;
            this->recursionAddNumber(candidates, nextPosition, target, next, result);
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
    vector<int> candidates { 10, 1, 2, 7, 6, 1, 5 };
    int target = 8;

    auto result = s.combinationSum2(candidates, target);
    for (auto row: result) {
        copy(row.begin(), row.end(), std::ostream_iterator<int>(cout, ","));
        cout << endl;
    }

    candidates = vector<int> { 2, 5, 2, 1, 2 };
    target = 5;

    result = s.combinationSum2(candidates, target);
    for (auto row: result) {
        copy(row.begin(), row.end(), std::ostream_iterator<int>(cout, ","));
        cout << endl;
    }
    
    return 0;
}
