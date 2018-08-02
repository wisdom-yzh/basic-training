#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void recursionCombine(int n, int i, int k, vector<int> &subResult, vector<vector<int>> &result) {
        if (k == 0) {
            result.push_back(subResult);
            return;
        }
        for (int ii = i + 1; ii <= n - k + 1; ii++) {
            subResult.push_back(ii);
            this->recursionCombine(n, ii, k - 1, subResult, result);
            subResult.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        for (int i = 1; i <= n - k + 1; i++) {
            vector<int> subResult { i };
            this->recursionCombine(n, i, k - 1, subResult, result);
        }
        return result;
    }
};

int main() {
    for (auto &vec: Solution().combine(4, 2)) {
        for (auto &i: vec) {
            cout << i << ',';
        }
        cout << endl;
    }
    return 0;
}
