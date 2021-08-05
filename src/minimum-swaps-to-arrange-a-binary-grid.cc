#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> zeroCount;

        for (int y = 0; y < grid.size(); y++) {
            int count = 0;
            for (int x = grid[y].size() - 1; x >= 0; x--) {
                if (grid[y][x] == 0) {
                    count++;
                } else {
                    break;
                }
            }
            zeroCount.push_back(count);
        }

        int res = 0;

        for (int y = 0; y < grid.size() - 1; y++) {
            auto iter = zeroCount.begin();
            for (; iter != zeroCount.end(); iter++) {
                if (*iter >= grid[0].size() - 1 - y) {
                    res += distance(zeroCount.begin(), iter) - y;
                    zeroCount.erase(iter);
                    zeroCount.insert(zeroCount.begin(), 0);
                    break;
                }
            }
            if (iter == zeroCount.end()) {
                return -1;
            }
        }

        return res;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{0,0,1},{1,1,0},{1,0,0}},
        {{0,1,1,0},{0,1,1,0},{0,1,1,0},{0,1,1,0}},
        {{1,0,0},{1,1,0},{1,1,1}}
    };
    for (auto &testCase: testCases) {
        cout << Solution().minSwaps(testCase) << endl;
    }
    return 0;
}
