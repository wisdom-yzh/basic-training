#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int, int>> A, B;
        uint64_t ans = 0;

        for(auto &i: orders) {
            if (i[2] == 0) {
                A.push({i[0], i[1]});
            } else {
                B.push({-i[0], i[1]});
            }
            ans += i[1];

            while (!A.empty()) {
                if (B.empty() || -B.top().first > A.top().first) {
                    break;
                }
                auto x = A.top(), y = B.top();
                A.pop();
                B.pop();

                int nu = min(x.second, y.second);
                x.second -= nu;
                y.second -= nu;
                ans -= 2 * nu;
                if (x.second) {
                    A.push(x);
                } else {
                    B.push(y);
                }
            }
        }
        return ans % MOD;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{10,5,0},{15,2,1},{25,1,1},{30,4,0}},
        {{7,1000000000,1},{15,3,0},{5,999999995,0},{5,1,1}},
    };
    for (auto &testCase: testCases) {
        cout << Solution().getNumberOfBacklogOrders(testCase) << endl;
    }
    return 0;
}
