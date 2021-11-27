#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        const int N = grid[0].size();
        vector<int> result(grid[0].size(), -1);

        for (int i = 0; i < N; i++) {
            int x = i;
            for (const auto &row: grid) {
                if (x + 1 < N && row[x] == 1 && row[x + 1] == 1) {
                    x++;
                } else if (x - 1 >= 0 && row[x] == -1 && row[x - 1] == -1) {
                    x--;
                } else {
                    x = -1;
                    break;
                }
            }
            result[i] = x;
        }
        return result;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{1,1,1,-1,-1},{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1}},
        {{-1}},
        {{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1},{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1}}
    };
    for (auto &testCase: testCases) {
        for (auto &x: Solution().findBall(testCase)) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}
