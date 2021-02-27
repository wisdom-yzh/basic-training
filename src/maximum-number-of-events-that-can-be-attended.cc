#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        std::sort(events.begin(), events.end(), [] (vector<int> &e1, vector<int> &e2) {
            return e1[0] < e2[0];
        });

        int res = 0, last = 1, i = 0;
        std::priority_queue<int, vector<int>, std::greater<int>> q;

        while (i < events.size() || !q.empty()) {
            while (i < events.size() && events[i][0] == last) {
                q.push(events[i++][1]);
            }

            while (!q.empty() && q.top() < last) {
                q.pop();
            }

            if (!q.empty()) {
                q.pop();
                res++;
            }
            last++;
        }

        return res;

    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{1,2},{2,3},{3,4}},
        {{1,2},{2,3},{3,4},{1,2}},
        {{1,4},{4,4},{2,2},{3,4},{1,1}}
    };
    for (auto &testCase: testCases) {
        cout << Solution().maxEvents(testCase) << endl;
    }
    return 0;
}
