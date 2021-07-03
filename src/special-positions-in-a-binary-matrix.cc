#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        if (!mat.size()) {
            return 0;
        }

        int rows = mat.size(), cols = mat[0].size();
        vector<int> rowCount(rows, 0), colCount(cols, 0);
        vector<pair<int, int>> one;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                    one.push_back({i, j});
                }
            }
        }

        int num = 0;
        for (auto &p: one) {
            if (rowCount[p.first] == 1 && colCount[p.second] == 1) {
                num++;
            }
        }

        return num;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {
            {1,0,0},
            {0,0,1},
            {1,0,0},
        },
        {
            {1,0,0},
            {0,1,0},
            {0,0,1},
        },
        {
            {0,0,0,1},
            {1,0,0,0},
            {0,1,1,0},
            {0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {1,0,0,0,0},
            {0,1,0,0,0},
            {0,0,1,0,0},
            {0,0,0,1,1},
        }
    };
    for (auto &testCase: testCases) {
        cout << Solution().numSpecial(testCase) << endl;
    }
    return 0;
}
