#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (arr[start] == -1) {
            return false;
        }
        if (arr[start] == 0) {
            return true;
        }
        int s = arr[start];
        arr[start] = -1;
        return (start + s < arr.size() && canReach(arr, start + s)) ||
            (start - s >= 0 && canReach(arr, start - s));
    }
};

int main() {
    vector<pair<vector<int>, int>> testCases {
        { {4,2,3,0,3,1,2}, 5 },
        { {4,2,3,0,3,1,2}, 0 },
        { {3,0,2,1,2}, 2 }
    };
    for (auto &testCase: testCases) {
        cout << boolalpha << Solution().canReach(testCase.first, testCase.second) << endl;
    }
    return 0;
}
