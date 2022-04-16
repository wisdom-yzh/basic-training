#include <ctime>
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> r(52, 0);
        for (auto &range: ranges) {
            r[range[0]]++;
            r[range[1] + 1]--;
        }
        for (int i = 1; i < r.size(); i++) {
            r[i] += r[i - 1];
        }
        for (int i = left; i <= right; i++) {
            if (r[i] == 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<tuple<vector<vector<int>>, int, int>> testCases {
        { {{1,2},{3,4},{5,6}}, 2, 5 },
        { {{1,10},{10,20}}, 21, 21 },
    };
    for (auto &[ranges, left, right]: testCases) {
        cout << boolalpha << Solution().isCovered(ranges, left, right) << endl;
    }
    return 0;
}
