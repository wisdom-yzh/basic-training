#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> result(arr.size(), 0);
        int maxValue = 0;

        for (int i = arr.size() - 1; i >= 0; i--) {
            if (i == arr.size() - 1) {
                result[i] = -1;
                maxValue = arr[i];
            } else {
                result[i] = maxValue;
                maxValue = std::max(maxValue, arr[i]);
            }
        }

        return result;
    }
};

int main() {
    vector<vector<int>> testCases {
        { 17,18,5,4,6,1 }
    };
    for (auto &testCase: testCases) {
        for (auto &num: Solution().replaceElements(testCase)) {
            cout << num << ' ';
        }
        cout << endl;
    }
    return 0;
}
