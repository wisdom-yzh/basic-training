#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        std::sort(boxTypes.begin(), boxTypes.end(), [] (const vector<int> &a, const vector<int> &b) {
            return a[1] > b[1];
        });

        int res = 0;
        for (int i = 0; i < boxTypes.size(); i++) {
            int count = boxTypes[i][0];
            int unitSize = boxTypes[i][1];

            if (count < truckSize) {
                res += (count * unitSize);
                truckSize -= count;
            } else {
                res += (truckSize * unitSize);
                break;
            }
        }
        return res;
    }
};

int main() {
    vector<pair<vector<vector<int>>, int>> testCases {
        { {{1,3},{2,2},{3,1}}, 4 },
        { {{5,10},{2,5},{4,7},{3,9}}, 10 }
    };
    for (auto &[boxTypes, truckSize]: testCases) {
        cout << Solution().maximumUnits(boxTypes, truckSize) << endl;
    }
    return 0;
}
