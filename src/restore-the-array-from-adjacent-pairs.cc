#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        std::map<int, int> count;
        std::map<int, vector<int>> paths;

        for (auto &p: adjacentPairs) {
            count[p[0]]++;
            count[p[1]]++;
            paths[p[0]].push_back(p[1]);
            paths[p[1]].push_back(p[0]);
        }

        vector<int> res;
        for (auto &[start, len]: count) {
            if (len == 1) {
                res.push_back(start);
                break;
            }
        }

        while (res.size() < adjacentPairs.size() + 1) {
            auto from = res.back();
            auto iter = paths.find(from);
            auto to = iter->second.front();

            res.push_back(to);
            auto iter2 = paths.find(to);
            if (iter2->second[0] == from) {
                iter2->second.erase(iter2->second.begin());
            } else {
                iter2->second.pop_back();
            }

            paths.erase(iter);
        }

        return res;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{2,1},{3,4},{3,2}},
        {{4,-2},{1,4},{-3,1}},
        {{100000,-100000}}
    };
    for (auto &testCase: testCases) {
        for (auto &x: Solution().restoreArray(testCase)) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}
