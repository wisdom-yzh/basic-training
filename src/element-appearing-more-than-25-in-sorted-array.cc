#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        const auto SIZE = arr.size();
        std::sort(arr.begin(), arr.end());

        int prev = arr[0];
        int count = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == prev) {
                count++;
                if (count > SIZE / 4.0) {
                    return arr[i];
                }
            } else {
                prev = arr[i];
                count = 1;
            }
        }

        return arr[0];
    }
};

int main() {
    vector<vector<int>> testCases {
        { 1,2,2,6,6,6,6,7,10 }
    };
    for (auto &testCase: testCases) {
        cout << Solution().findSpecialInteger(testCase) << endl;
    }
    return 0;
}
