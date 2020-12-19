#include <vector>
#include <tuple>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> result(2, vector<int>(colsum.size(), 0));

        bool err = false;
        for (int i = 0; i < colsum.size() && !err; i++) {
            if (colsum[i] == 0) {
                result[0][i] = result[1][i] = 0;
            } else if (colsum[i] == 2) {
                result[0][i] = result[1][i] = 1;
                upper--;
                lower--;
            } else {
                int &rowCount = upper >= lower ? upper : lower;
                int r = upper >= lower ? 0 : 1;
                result[r][i] = 1;
                result[1 - r][i] = 0;
                rowCount--;
            }

            if (upper < 0 || lower < 0) {
                err = true;
                break;
            }
        }

        if (upper > 0 || lower > 0) {
            err = true;
        }

        return err ? vector<vector<int>>{} : result;
    }
};

int main() {
    vector<tuple<int, int, vector<int>>> testCases {
        { 2, 1, { 1, 1, 1 } },
        { 2, 3, { 2, 2, 1, 1 } },
        { 5, 5, { 2, 1, 2, 0, 1, 0, 1, 2, 0, 1 } }
    };

    for (auto testCase: testCases) {
        for (auto &row: Solution().reconstructMatrix(
            get<0>(testCase),
            get<1>(testCase),
            get<2>(testCase))
        ) {
            for (auto &x: row) {
                cout << x << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
