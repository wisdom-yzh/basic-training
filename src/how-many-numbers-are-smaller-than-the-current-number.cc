#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int count[101];
        std::fill(count, count + 100, 0);

        for (auto &num: nums) {
            count[num]++;
        }

        int smallerNumbers = 0;
        for (int i = 0; i <= 100; i++) {
            if (count[i] != 0) {
                int t = smallerNumbers + count[i];
                count[i] = smallerNumbers;
                smallerNumbers = t;
            }
        }

        for (auto &num: nums) {
            num = count[num];
        }
        return nums;
    }
};

int main() {
    vector<vector<int>> testCases {
        {8,1,2,2,3},
        {6,5,4,8},
        {7,7,7,7}
    };

    for (auto &testCase: testCases) {
        for (auto &x: Solution().smallerNumbersThanCurrent(testCase)) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}
