#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        std::map<int, int> v;
        for (auto &edge: edges) {
            v[edge[0]]++;
            v[edge[1]]++;
        }

        int maxCount = 0, maxIdx = 0;
        for (auto &[idx, count]: v) {
            if (count > maxCount) {
                maxCount = count;
                maxIdx = idx;
            }
        }

        return maxIdx;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{1,2},{2,3},{4,2}},
        {{1,2},{5,1},{1,3},{1,4}}
    };
    for (auto &testCase: testCases) {
        cout << Solution().findCenter(testCase) << endl;
    }
    return 0;
}
