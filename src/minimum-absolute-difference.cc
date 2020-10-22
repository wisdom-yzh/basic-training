#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> result;
        int minValue = std::numeric_limits<int>::max();

        std::sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i + 1] - arr[i] < minValue) {
                minValue = arr[i + 1] - arr[i];
                result.clear();
                result.push_back({ arr[i], arr[i + 1] });
            } else if (arr[i + 1] - arr[i] == minValue) {
                result.push_back({ arr[i], arr[i + 1] });
            }
        }

        return result;
    }
};

int main() {
    vector<vector<int>> testCases {
        { 4,2,1,3 },
        { 1,3,6,10,15 },
        { 3,8,-10,23,19,-4,-14,27 }
    };
    for (auto &testCase: testCases) {
        for (auto &row: Solution().minimumAbsDifference(testCase)) {
            cout << "[" << row[0] << ',' << row[1] << "] ";
        }
        cout << endl;
    }
    return 0;
}
