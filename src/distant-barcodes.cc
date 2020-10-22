#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        std::map<int, int> countByValue;
        for (auto &el: barcodes) {
            countByValue[el]++;
        }

        std::map<int, vector<int>> countMap;
        for (auto c: countByValue) {
            countMap[c.second].push_back(c.first);
        }

        int k = 0, total = 0;
        vector<int> result(barcodes.size(), 0);
        for (auto iter = countMap.rbegin(); iter != countMap.rend(); iter++) {
            int count = iter->first;
            for (auto &value: iter->second) {
                for (int i = 0; i < count; i++) {
                    result[k] = value;
                    total++;
                    if (total == barcodes.size()) {
                        break;
                    }
                    k = (k + 2) % barcodes.size();
                    while (result[k] != 0) {
                        k = (k + 1) % barcodes.size();
                    }
                }
            }
        }

        return result;
    }
};

int main() {
    vector<vector<int>> testCases {
        {1,1,1,2,2,2},
        {1,1,1,1,2,2,3,3},
        {2,2,1,3}
    };

    for (auto &testCase: testCases) {
        for (const auto &el: Solution().rearrangeBarcodes(testCase)) {
            cout << el << ' ';
        }
        cout << endl;
    }
    return 0;
}
