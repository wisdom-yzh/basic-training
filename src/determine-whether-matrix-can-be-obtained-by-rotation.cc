#include <iostream>
#include <pthread.h>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < 4; i++) {
            if (mat == target) {
                return true;
            }
            mat = this->rotate90(mat);
        }
        return false;
    }

    vector<vector<int>> rotate90(vector<vector<int>>& mat) {
        const int M = mat.size();
        vector<vector<int>> newMat(mat);

        for (int r = 0; r < M; r++) {
            for (int c = 0; c < M; c++) {
                newMat[c][M - 1 - r] = mat[r][c];
            }
        }

        return newMat;
    }
};

int main() {
    vector<pair<vector<vector<int>>, vector<vector<int>>>> testCases {
        {
            {{0,1},{1,0}},
            {{1,0},{0,1}}
        },
        {
            {{0,0,0},{0,1,0},{1,1,1}},
            {{1,1,1},{0,1,0},{0,0,0}}
        }
    };
    for (auto &[mat, target]: testCases) {
        cout << boolalpha << Solution().findRotation(mat, target) << endl;
    }
    return 0;
}
