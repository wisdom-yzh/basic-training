#include <vector>
#include <map>
#include <set>
#include <limits>
#include <iostream>
using namespace std;

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int result = std::numeric_limits<int>::max();
        std::map<int, std::set<int>> dict;
        for (const auto &point: points) {
            dict[point[0]].insert(point[1]);
        }

        for (auto it = dict.begin(); it != dict.end(); it++) {
            auto it1 = it;
            it1++;
            int x0 = it->first;
            for (; it1 != dict.end(); it1++) {
                int x1 = it1->first;
                vector<int> y_;
                for (auto& y0 : it->second) {
                    if (it1->second.count(y0)) {
                        y_.push_back(y0);
                    }
                }
                for (int i = 1; i < y_.size(); i++) {
                    result = min(result, (x1 - x0) * (y_[i] - y_[i - 1]));
                }
            }
        }
        return result == std::numeric_limits<int>::max() ? 0 : result;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{1,1},{1,3},{3,1},{3,3},{2,2}},
        {{1,1},{1,3},{3,1},{3,3},{4,1},{4,3}}
    };
    for (auto &testCase: testCases) {
        cout << Solution().minAreaRect(testCase) << endl;
    }
    return 0;
}
