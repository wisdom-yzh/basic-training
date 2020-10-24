#include <vector>
#include <limits>
#include <iostream>
using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        vector<int> dp(books.size(), std::numeric_limits<int>::max());
        dp[0] = books[0][1];

        for (int i = 1; i < books.size(); i++) {
            int j = i, width = 0, height = 0;
            for (; j >= 0; j--) {
                if (width + books[j][0] > shelf_width) {
                    break;
                }
                height = std::max(height, books[j][1]);
                width += books[j][0];
                dp[i] = std::min(dp[i], (j > 0 ? dp[j - 1] : 0) + height);
            }
        }

        return dp.back();
    }
};

int main() {
    vector<pair<vector<vector<int>>, int>> testCases {
        { {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}}, 4 },
        { {{1,3},{2,4},{3,2}}, 6 },
        { {{7,3},{8,7},{2,7},{2,5}}, 10 }
    };
    for (auto &testCase: testCases) {
        cout << Solution().minHeightShelves(testCase.first, testCase.second) << endl;
    }
    return 0;
}
