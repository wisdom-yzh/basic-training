#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> intervals;
        int i = 0, j = 0;

        while (i < A.size() && j < B.size()) {
            auto &a = A[i];
            auto &b = B[j];

            if (a[0] <= b[0]) {
                if (a[1] >= b[1]) {
                    intervals.push_back({ b[0], b[1] });
                    j++;
                } else {
                    if (a[1] >= b[0] && a[1] <= b[1]) {
                        intervals.push_back({ b[0], a[1] });
                    }
                    i++;
                }
            } else {
                if (b[1] >= a[1]) {
                    intervals.push_back({ a[0], a[1] });
                    i++;
                } else {
                    if (b[1] >= a[0] && b[1] <= a[1]) {
                        intervals.push_back({ a[0], b[1] });
                    }
                    j++;
                }
            }
        }

        return intervals;
    }
};

int main() {
    vector<pair<vector<vector<int>>, vector<vector<int>>>> testCases {
        {{{0,2},{5,10},{13,23},{24,25}}, {{1,5},{8,12},{15,24},{25,26}}}
    };

    for (auto &testCase: testCases) {
        for (const auto &row: Solution().intervalIntersection(testCase.first, testCase.second)) {
            cout << '[' << row[0] << ',' << row[1] << ']' << ',';
        }
        cout << endl;
    }
    return 0;
}
