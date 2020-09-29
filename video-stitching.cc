#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        std::sort(clips.begin(), clips.end(), [](vector<int> &clip1, vector<int> &clip2) {
            if (clip1[0] == clip2[0]) {
                return clip1[1] < clip2[1];
            }
            return clip1[0] < clip2[0];
        });

        vector<int> stitchingLength(clips.size(), -1);
        int minLength = -1;

        for (int i = 0; i < clips.size(); i++) {
            if (clips[i][0] == 0) {
                stitchingLength[i] = 1;
            } else {
                for (int j = 0; j < i; j++) {
                    if (stitchingLength[j] != -1 &&
                        clips[j][0] <= clips[i][0] &&
                        clips[j][1] >= clips[i][0] &&
                        clips[j][1] <= clips[i][1]) {
                        stitchingLength[i] = stitchingLength[i] == -1
                            ? stitchingLength[j] + 1
                            : std::min(stitchingLength[i], stitchingLength[j] + 1);
                    }
                }
            }

            if (stitchingLength[i] != -1 && clips[i][1] >= T) {
                minLength = minLength == -1
                    ? stitchingLength[i]
                    : std::min(stitchingLength[i], minLength);
            }
        }

        return minLength;
    }
};

int main() {
    vector<pair<vector<vector<int>>, int>> testCases {
        { {{0,2},{4,6},{8,10},{1,9},{1,5},{5,9}}, 10 }, // 3
        { {{0,1},{1,2}}, 5 }, // -1
        { {{0,1},{6,8},{0,2},{5,6},{0,4},{0,3},{6,7},{1,3},{4,7},{1,4},{2,5},{2,6},{3,4},{4,5},{5,7},{6,9}}, 9 }, // 3
        { {{0,4},{2,8}}, 5 } // 2
    };

    for (auto &testCase: testCases) {
        cout << Solution().videoStitching(testCase.first, testCase.second) << endl;
    }
    return 0;
}
