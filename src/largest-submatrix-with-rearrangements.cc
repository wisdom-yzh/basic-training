#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        const int M = matrix.size(), N = matrix[0].size();
        vector<int> height(N);
        int res = 0;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] == 1) {
                    height[j] += 1;
                } else {
                    height[j] = 0;
                }
            }
            vector<int> sh(height);
            std::sort(sh.begin(), sh.end());
            for (int k = N - 1; k >= 0 && sh[k] > 0; k--) {
                int w = N - k;
                int h = sh[k];
                res = std::max(res, w * h);
            }
        }

        return res;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        { {0,0,1},{1,1,1},{1,0,1} },
        { {1,0,1,0,1} },
        { {0,0},{0,0} }
    };
    for (auto &mat: testCases) {
        cout << Solution().largestSubmatrix(mat) << endl;
    }
    return 0;
}
