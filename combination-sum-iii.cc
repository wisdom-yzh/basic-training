#include <vector>
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    void combinationSum3(vector<vector<int>> &v, vector<int> &row, bool *used, int k, int n) {
        if (k == 0) {
            if (n != 0) {
                return;
            }
            vector<int> r0 = row;
            sort(r0.begin(), r0.end());
            for (auto &r: v) {
                if (equal(r0.begin(), r0.end(), r.begin())) {
                    return;
                }
            }
            v.push_back(r0);
        }
        for (int i = 1; i <= min(n, 9); i++) {
            if (!used[i]) {
                row.push_back(i);
                used[i] = true;
                combinationSum3(v, row, used, k - 1, n - i);
                used[i] = false;
                row.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> v;
        vector<int> r;
        bool used[11];
        fill(used, used + 11, false);
        combinationSum3(v, r, used, k, n);
        return v;
    }
};

int main() {
    for (auto &row: Solution().combinationSum3(3, 9)) {
        for (auto &col: row) {
            cout << col << ',';
        }
        cout << endl;
    }
    return 0;
}
