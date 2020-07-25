#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int maxScore = 0, score = 0, i = 0, j = tokens.size() - 1;
        std::sort(tokens.begin(), tokens.end());

        while (i <= j) {
            if (P >= tokens[i]) {
                score++;
                maxScore = std::max(maxScore, score);
                P -= tokens[i];
                i++;
            } else if (score > 0) {
                score--;
                P += tokens[j];
                j--;
            } else {
                break;
            }
        }

        return maxScore;
    }
};

int main() {
    vector<pair<vector<int>, int>> cases {
        {{ 100 }, 50 },
        {{ 100, 200 }, 150 },
        {{ 100, 200, 300, 400 }, 200}
    };
    for (auto &testCase: cases) {
        cout << Solution().bagOfTokensScore(testCase.first, testCase.second) << endl;
    }
    return 0;
}
