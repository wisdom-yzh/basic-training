#include <vector>
#include <iostream>
#include <tuple>
using namespace std;

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        vector<bool> res;
        vector<uint64_t> sum(candiesCount.size() + 1, 0);
        for (int i = 0; i < candiesCount.size(); i++) {
            sum[i + 1] = sum[i] + candiesCount[i];
        }

        for (auto &query: queries) {
            int type = query[0];
            int day = query[1];
            int cap = query[2];

            uint64_t p = day, q = (day + 1l) * (uint64_t)cap;
            res.push_back(p < sum[type + 1] && q > sum[type]);
        }
        return res;
    }
};

int main() {
    vector<pair<vector<int>, vector<vector<int>>>> testCases {
        { {7,4,5,3,8}, {{0,2,2},{4,2,4},{2,13,1000000000}} },
        { {5,2,6,4,1}, {{3,1,2},{4,10,3},{3,10,100},{4,100,30},{1,3,1}} }
    };
    for (auto &[candiesCount, queries]: testCases) {
        for (auto x: Solution().canEat(candiesCount, queries)) {
            cout << boolalpha << x << ' ';
        }
        cout << endl;
    }
    return 0;
}
