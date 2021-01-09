#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <iterator>
#include <tuple>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        auto cmp = [](pair<int, int> &a, pair<int, int> &b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first > b.first;
        };

        std::priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for (int r = 0; r < mat.size(); r++) {
            auto &row = mat[r];
            auto i = std::find(row.begin(), row.end(), 0);
            q.emplace(make_pair(std::distance(row.begin(), i), r));
        }

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(q.top().second);
            q.pop();
        }
        return result;
    }
};

int main() {
    vector<pair<vector<vector<int>>, int>> testCases {
        {
            {{1,1,0,0,0},
             {1,1,1,1,0},
             {1,0,0,0,0},
             {1,1,0,0,0},
             {1,1,1,1,1}},
            3
        },
        {
            {{1,0,0,0},
             {1,1,1,1},
             {1,0,0,0},
             {1,0,0,0}},
            2
        }
    };
    for (auto &testCase: testCases) {
        for (auto &x: Solution().kWeakestRows(testCase.first, testCase.second)) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}
