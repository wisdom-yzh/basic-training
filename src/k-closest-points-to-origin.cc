#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto cmp = [](vector<int> &p1, vector<int> &p2) -> bool {
            return p1[0] * p1[0] + p1[1] * p1[1] > p2[0] * p2[0] + p2[1] * p2[1];
        };
        std::priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);
        for (const auto &point: points) {
            q.push(point);
        }

        vector<vector<int>> result;
        for (int i = 0; i < K; i++) {
            result.push_back(q.top());
            q.pop();
        }
        return result;
    }
};

int main() {
    vector<pair<vector<vector<int>>, int>> testCases {
        {{{1,3},{-2,2}}, 1},
        {{{3,3},{5,-1},{-2,4}}, 2}
    };
    for (auto &testCase: testCases) {
        for (auto &point: Solution().kClosest(testCase.first, testCase.second)) {
            cout << '(' << point[0] << ',' << point[1] << ')' << '\t';
        }
        cout << endl;
    }
    return 0;
}
