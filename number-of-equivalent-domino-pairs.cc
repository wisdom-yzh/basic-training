#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        std::map<std::vector<int>, int> dict;
        for (auto &domino: dominoes) {
            if (domino[0] > domino[1]) {
                std::swap(domino[0], domino[1]);
            }
            dict[domino]++;
        }

        int result = 0;
        for (auto &p: dict) {
            if (p.second == 1) {
                continue;
            }
            result += (p.second  * (p.second - 1)) / 2;
        }

        return result;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{1,2},{2,1},{3,4},{5,6}}
    };
    for (auto &testCase: testCases) {
        cout << Solution().numEquivDominoPairs(testCase);
    }
    return 0;
}
