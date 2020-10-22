#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> sums;
        int sum = 0;
        for (const auto &num: A) {
            if (num % 2 == 0) {
                sum += num;
            }
        }

        for (const auto &query: queries) {
            int i = query[1];
            int val = query[0] + A[i];
            if (A[i] % 2 == 0 && val % 2 == 0) {
                sum += query[0];
            } else if (A[i] % 2 == 0 && val % 2 != 0) {
                sum -= A[i];
            } else if (A[i] % 2 != 0 && val % 2 == 0) {
                sum += val;
            }
            sums.push_back(sum);
            A[i] = val;
        }

        return sums;
    }
};

int main() {
    vector<pair<vector<int>, vector<vector<int>>>> testCases {
        { {1,2,3,4}, {{1,0},{-3,1},{-4,0},{2,3}} }
    };

    for (auto &testCase: testCases) {
        for (const auto &num: Solution().sumEvenAfterQueries(testCase.first, testCase.second)) {
            cout << num << ' ';
        }
        cout << endl;
    }
    return 0;
}
