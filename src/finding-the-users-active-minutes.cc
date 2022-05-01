#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        std::unordered_map<int, std::unordered_set<int>> dict;
        for (auto &log: logs) {
            dict[log[0]].emplace(log[1]);
        }

        vector<int> res(k, 0);
        for (auto &[_, s]: dict) {
            res[s.size() - 1]++;
        }
        return res;
    }
};

int main() {
    vector<pair<vector<vector<int>>, int>> testCases {
        { {{0,5},{1,2},{0,2},{0,5},{1,3}}, 5 },
        { {{1,1},{2,2},{2,3}}, 4 },
    };
    for (auto &[logs, k]: testCases) {
        for (auto &x: Solution().findingUsersActiveMinutes(logs, k)) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}
