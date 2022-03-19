#include <vector>
#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto cmp = [](pair<int, int> &a, pair<int, int> &b) {
            return (double)(a.second - a.first) / (a.second + 1) / a.second <
                (double)(b.second - b.first) / (b.second + 1) / b.second;
        };
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for (auto &c: classes) {
            q.push({c[0], c[1]});
        }

        for (int i = 0; i < extraStudents; i++) {
            auto [a, b] = q.top();
            q.pop();
            q.push({ a + 1, b + 1 });
        }

        double result = 0;
        while (!q.empty()) {
            auto [a, b] = q.top();
            result += (double)a / b;
            q.pop();
        }

        return result / classes.size();
    }
};

int main() {
    vector<pair<vector<vector<int>>, int>> testCases {
        { {{1,2},{3,5},{2,2}}, 2 },
        { {{2,4},{3,9},{4,5},{2,10}}, 4 }
    };

    for (auto &[classes, extraStudents]: testCases) {
        cout << Solution().maxAverageRatio(classes, extraStudents) << endl;
    }
    return 0;
}
