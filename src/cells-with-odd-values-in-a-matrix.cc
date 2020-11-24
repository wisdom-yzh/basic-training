#include <iostream>
#include <tuple>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> rows(n, 0);
        vector<int> cols(m, 0);

        for (auto &p: indices) {
            rows[p[0]]++;
            cols[p[1]]++;
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((rows[i] + cols[j]) % 2 != 0)  {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    vector<tuple<int, int, vector<vector<int>>>> testCases {
        { 2, 3, {{0,1},{1,1}} },
        { 2, 2, {{1,1},{0,0}} }
    };
    for (auto &testCase: testCases) {
        cout << Solution().oddCells(get<0>(testCase), get<1>(testCase), get<2>(testCase)) << endl;
    }
    return 0;
}
