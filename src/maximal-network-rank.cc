#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int res = 0;

        vector<vector<bool>> mat(n, vector<bool>(n, false));
        vector<int> roadCount(n, 0);

        for (auto &road: roads) {
            mat[road[0]][road[1]] = mat[road[1]][road[0]] = true;
            roadCount[road[0]]++;
            roadCount[road[1]]++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                res = std::max(
                    res,
                    roadCount[i] + roadCount[j] - (mat[i][j] ? 1 : 0)
                );
            }
        }

        return res;
    }
};

int main() {
    vector<pair<int, vector<vector<int>>>> testCases {
        { 4, {{0,1},{0,3},{1,2},{1,3}} },
        { 5, {{0,1},{0,3},{1,2},{1,3},{2,3},{2,4}} },
        { 8, {{0,1},{1,2},{2,3},{2,4},{5,6},{5,7}} },
    };
    for (auto &[n, roads] : testCases) {
        cout << Solution().maximalNetworkRank(n, roads) << endl;
    }
    return 0;
}
