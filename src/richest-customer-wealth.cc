#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        for (auto &account: accounts) {
            res = std::max(res, std::accumulate(account.begin(), account.end(), 0));
        }
        return res;
    }
};

int main() {
    std::vector<vector<vector<int>>> testCases {
        {{1,2,3},{3,2,1}},
        {{1,5},{7,3},{3,5}},
        {{2,8,7},{7,1,3},{1,9,5}}
    };
    for (auto &testCase : testCases) {
        cout << Solution().maximumWealth(testCase) << endl;
    }
    return 0;
}
